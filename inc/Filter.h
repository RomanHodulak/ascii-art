#ifndef ASCII_ART_FILTER_H
#define ASCII_ART_FILTER_H

#include <cstdio>
#include "Pixel.h"

/**
 * Abstract filter. Filters are classes that modifies pixels in some way and returns the result as a new pixel.
 */
class Filter {
public:

	/**
	 * Applies this filter to a copy of given pixel and returns it.
	 *
	 * @param pixel Pixel to filter.
	 * @return Modified pixel.
	 */
	virtual Pixel apply(const Pixel & pixel) const = 0;
};

#endif //ASCII_ART_FILTER_H
