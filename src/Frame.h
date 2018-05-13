#ifndef ASCII_ART_FRAME_H
#define ASCII_ART_FRAME_H

#include <cstdio>
#include "AsciiPrinter.h"

/**
 * Contains pixel matrix stored in memory.
 */
class Frame {
public:

	/**
	 * Prints the frame.
	 *
	 * @param output Output to print the frame to.
	 * @param printer Printer to print the frame with.
	 * @param filter Filter that gets applied to every pixel of the frame.
	 */
	void print(FILE * output, AsciiPrinter * printer, Filter * filter) const;
};

#endif //ASCII_ART_FRAME_H
