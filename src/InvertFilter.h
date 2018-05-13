#ifndef ASCII_ART_INVERTFILTER_H
#define ASCII_ART_INVERTFILTER_H

#include "Filter.h"

/**
 * Inverts pixel channels (colors).
 */
class InvertFilter : public Filter {
public:

	/**
	 * Inverts pixel channels.
	 *
	 * @param pixel Pixel to invert the channels of.
	 * @return Inverted pixel.
	 */
	Pixel apply(const Pixel & pixel) const override;
};

#endif //ASCII_ART_INVERTFILTER_H
