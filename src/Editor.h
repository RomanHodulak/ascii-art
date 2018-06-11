#ifndef ASCII_ART_EDITOR_H
#define ASCII_ART_EDITOR_H

#include <ncurses.h>
#include <string>
#include <vector>
#include "ui/PlayerControl.h"
#include "ui/FilterPanelControl.h"
#include "ui/FilterMenuControl.h"

#define KEY_SPACE ' '
#define CTRL_MASK 31
#define KEY_ESC 27

using namespace std;

/**
 * ASCII animation player and editor with simple UI. Renders to terminal via ncurses library.
 */
class Editor {
private:

	/** Maps key codes to functions. */
	std::map<int, void (Editor::*)()> keyMap;

	/** Maps key codes to functions. Overrides the main key map if it has any values. */
	std::map<int, void (Editor::*)()> overridenKeyMap;

	/** Indicates editor run state. */
	bool running = false;

	/** Control that plays the animation. */
	PlayerControl * player = nullptr;

	/** Control that enables user to view and edit filters used. */
	FilterPanelControl * panel = nullptr;

	/** Control that enables user to choose a new filter. */
	FilterMenuControl * filterMenu = nullptr;

	/** If TRUE, displays filter menu window and overrides key map. */
	bool filterMenuVisible = false;

	/** Indicates area that needs to be cleared before any rendering. Gets reset to NULL after it has been cleared. */
	Rectangle * clearRect = nullptr;

	void commandTogglePlay();

	void commandTogglePlayBackwards();

	void commandExit();

	void commandUp();

	void commandDown();

	void commandLeft();

	void commandRight();

	void commandShowFilterMenu();

	void commandCloseFilterMenu();

	void commandFilterMenuAccept();

	void commandFilterMenuUp();

	void commandFilterMenuDown();

	void commandDelete();

	void commandAccept();

	void commandEditFilterUp();

	void commandEditFilterDown();

	void commandLeaveFilterEdit();

	void commandSkipFrame();

	void commandSwapFrame();

	void commandFpsInc();

	void commandFpsDec();

public:

	Editor();

	~Editor();

	/**
	 * Runs the editor. Editor keeps running until user quits it (by pressing ESC).
	 *
	 * @tparam Iterator Forward iterator of strings.
	 * @param map File name of the map.
	 * @param files File names to load and display in the editor.
	 */
	template <typename Iterator>
	void run(const std::string & map, Iterator filesBegin, Iterator filesEnd);

	/**
	 * Marks an area to be cleared before rendering. Gets cleared only once.
	 *
	 * @param rectangle Area to clear.
	 */
	void clearArea(const Rectangle & rectangle);
};

#include "Editor.tpp"

#endif //ASCII_ART_EDITOR_H
