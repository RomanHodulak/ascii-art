#include "MultiImageSource.h"
#include "BmpImageSource.h"
#include "MultiFilter.h"
#include "GreyscaleFilter.h"
#include "NCursesBuf.h"
#include "InvertFilter.h"

template <typename Iterator>
void Editor::run(Iterator filesBegin, Iterator filesEnd) {
	if (!initscr()) {
		return;
	}

	noecho();
	raw();
	printw("Zadávání znaků ukončíte klávesou Enter:\n");

	MultiImageSource images;
	AsciiPrinter printer("map.txt");
	MultiFilter filter;

	for (Iterator it = filesBegin; it != filesEnd; ++it) {
		images.pushSource(BmpImageSource(* it));
	}

	filter.pushFilter(GreyscaleFilter());
	NCursesBuf windowBuf;
	std::ostream windowStream((std::basic_streambuf<char> *) & windowBuf);

	refresh();
	char ch;
	do {
		wmove(stdscr, 0, 0);
		images.getFrame(0).print(windowStream, printer, filter);
		ch = (char) getch();
		printw("ch = %c\n", ch);
		refresh();
	} while (ch != '\0' && ch != '\n');
}
