#include "NCursesBuf.h"

int NCursesBuf::overflow(int c) {
	return (printw("%c", c) == OK ? 1 : EOF);
}
