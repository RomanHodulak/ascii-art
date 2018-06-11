#include "NCursesBuf.h"

int NCursesBuf::overflow(int c) {
	int curx = getcurx(stdscr);
	int cury = getcury(stdscr);

	if (c == '\n') {
		if (cury >= (rect.height + rect.y) || cury >= getmaxy(stdscr) - 1) {
			// Ignore out of bounds
			return 1;
		}

		// Behave like newline but shift X to rectangle X
		return wmove(stdscr, cury + 1, rect.x) == OK ? 1 : EOF;
	}
	if (curx < rect.x && curx < getmaxx(stdscr)) {
		// Shift cursor but do not write
		return wmove(stdscr, cury, curx + 1) == OK ? 1 : EOF;
	}
	if (cury < rect.y
		|| cury >= (rect.height + rect.y)
		|| curx < rect.x
		|| curx >= (rect.width + rect.x)
		|| curx >= getmaxx(stdscr) - 1 // last character inputs newline causing ASCII rendering issues
		|| cury >= getmaxy(stdscr)
		) {
		// Ignore out of bounds
		return 1;
	}

	return (printw("%c", c) == OK ? 1 : EOF);
}

void NCursesBuf::setBoundaries(const Rectangle & rectangle) {
	this->rect = rectangle;
}

void NCursesBuf::resetPos() {
	wmove(stdscr, rect.y, rect.x);
}
