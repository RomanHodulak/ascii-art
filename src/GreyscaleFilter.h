#ifndef ASCII_ART_GREYSCALEFILTER_H
#define ASCII_ART_GREYSCALEFILTER_H

#include "Filter.h"

/**
 * Converts pixels with multiple channels into single channel ones.
 */
class GreyscaleFilter : public Filter {
public:

	/**
	 * Converts the pixel channels into a single channel with the average of its values.
	 *
	 * @param pixel Pixel to apply the filter to.
	 * @return Greyscale pixel.
	 */
	Pixel apply(const Pixel & pixel) const override;
};

#endif //ASCII_ART_GREYSCALEFILTER_H
