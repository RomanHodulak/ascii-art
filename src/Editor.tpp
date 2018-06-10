#include <ctime>
#include "MultiImageSource.h"
#include "BmpImageSource.h"
#include "MultiFilter.h"
#include "GreyscaleFilter.h"
#include "NCursesBuf.h"
#include "InvertFilter.h"
#include "BrightnessFilter.h"
#include "ui/PlayerControl.h"
#include "ui/SidePanelControl.h"
#include "ui/FilterMenuControl.h"

template <typename Iterator>
void Editor::run(Iterator filesBegin, Iterator filesEnd) {
	const static int panelWidth = 25;
	const static double clocksPerMs = CLOCKS_PER_SEC / 1000;

	if (!initscr()) {
		return;
	}

	ESCDELAY = 500;
	noecho();
	nocbreak();
	nodelay(stdscr, true);
	keypad(stdscr, true);
	raw();
	curs_set(0);

	AsciiPrinter printer("examples/map.txt");

	MultiImageSource images;
	for (Iterator it = filesBegin; it != filesEnd; ++it) {
		images.pushSource(BmpImageSource(* it));
	}

	NCursesBuf windowBuf;
	std::ostream windowStream(& windowBuf);

	int screenWidth = getmaxx(stdscr);
	int screenHeight = getmaxy(stdscr);
	this->panel = new SidePanelControl(Rectangle(0, 0, panelWidth, screenHeight));
	this->player = new PlayerControl(Rectangle(panelWidth, 0, screenWidth - panelWidth, screenHeight), images, printer, panel->getFilter());
	this->filterMenu = new FilterMenuControl(Rectangle(10, 10, 70, 10));

	this->panel->addFilterItem("Greyscale", GreyscaleFilter());

	this->filterMenu->addItem("Greyscale", [this]() {
		this->panel->addFilterItem(
			"Greyscale",
			GreyscaleFilter()
		);
	});
	this->filterMenu->addItem("Invert", [this]() {
		this->panel->addFilterItem(
			"Invert",
			InvertFilter()
		);
	});
	this->filterMenu->addItem("Brightness", [this]() {
		this->panel->addFilterItem(
			"Brightness",
			BrightnessFilter(),
			&BrightnessFilter::getBrightness,
			&BrightnessFilter::setBrightness
		);
	});

	std::clock_t prevTime = std::clock();
	this->running = true;

	while (this->running) {
		int key = getch();

		if (key != ERR) {
			auto * map = &this->keyMap;

			if (!this->overridenKeyMap.empty()) {
				map = &this->overridenKeyMap;
			}

			auto keyFunction = map->find(key);

			if (keyFunction != map->end()) {
				(this->*(keyFunction->second))();
			}
		}

		std::clock_t curTime = std::clock();
		double deltaTimeMs = (curTime - prevTime) / clocksPerMs;
		prevTime = curTime;

		this->player->update(deltaTimeMs);

		if (this->clearRect != nullptr) {
			windowBuf.setBoundaries(* this->clearRect);
			windowBuf.resetPos();

			for (size_t i = 0; i < this->clearRect->height; ++i) {
				for (size_t j = 0; j < this->clearRect->width; ++j) {
					windowStream << ' ';
				}
				windowStream << std::endl;
			}

			// Set boundaries to something before we delete the rectangle
			windowBuf.setBoundaries(this->player->getRect());

			delete this->clearRect;
			this->clearRect = nullptr;
		}

		windowBuf.setBoundaries(this->player->getRect());
		windowBuf.resetPos();
		windowStream << * this->player;

		windowBuf.setBoundaries(this->panel->getRect());
		windowBuf.resetPos();
		windowStream << * this->panel;

		if (this->filterMenuVisible) {
			windowBuf.setBoundaries(this->filterMenu->getRect());
			windowBuf.resetPos();
			windowStream << * this->filterMenu;
		}

		refresh();
	}

	delete this->player;
	delete this->panel;
	delete this->filterMenu;
	this->player = nullptr;
	this->panel = nullptr;
	this->filterMenu = nullptr;
	endwin();
}
