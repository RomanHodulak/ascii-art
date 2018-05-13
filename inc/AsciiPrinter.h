#ifndef ASCII_ART_ASCIIFILTER_H
#define ASCII_ART_ASCIIFILTER_H

#include <cstdio>
#include "Filter.h"

/**
 * Filters pixels as ASCII characters by mapping pixel brightness to a certain character. Map is load from file.
 * Brightness is mapped as a number in a range of 0..255. Map does not need to map all of the 256 values, filter chooses
 * the closest match if a brightness value is not present.
 *
 * Expected file format (key* is int(0..255) and value* is char):
 * key1 value1
 * key2 value2
 * ...
 */
class AsciiPrinter {
public:

	/**
	 * @param source File to get the map of int(0..255) whiteness to ASCII character.
	 */
	explicit AsciiPrinter(FILE * source);

	/**
	 * Converts the pixel to ascii character and prints it out.
	 *
	 * @param output Output to print to.
	 * @param pixel Pixel to filter.
	 */
	void print(FILE * output, const Pixel & pixel) const;
};

#endif //ASCII_ART_ASCIIFILTER_H
