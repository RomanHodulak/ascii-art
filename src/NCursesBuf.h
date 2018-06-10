#ifndef ASCII_ART_NCURSESBUF_H
#define ASCII_ART_NCURSESBUF_H

#include <streambuf>
#include <ncurses.h>
#include "ui/Rectangle.h"

class NCursesBuf : public std::streambuf {
private:

	/** Sets position and limits size. */
	Rectangle rect;

public:

	int overflow(int c) override;

	void setBoundaries(const Rectangle & rectangle);

	void resetPos();
};

#endif //ASCII_ART_NCURSESBUF_H
