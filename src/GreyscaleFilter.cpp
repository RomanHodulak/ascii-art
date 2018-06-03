#include "GreyscaleFilter.h"

Pixel GreyscaleFilter::apply(const Pixel & pixel) const {
	unsigned short greyscale = 0;

	for (size_t i = 0; i < pixel.getChannelsCount(); ++i) {
		greyscale += pixel.getChannel(i) / pixel.getChannelsCount();
	}

	return Pixel({greyscale});
}
