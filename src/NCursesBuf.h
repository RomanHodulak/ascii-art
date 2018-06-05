#ifndef ASCII_ART_NCURSESBUF_H
#define ASCII_ART_NCURSESBUF_H

#include <streambuf>
#include <ncurses.h>

class NCursesBuf : public std::streambuf {
public:
	int overflow(int c) override;
};

#endif //ASCII_ART_NCURSESBUF_H
