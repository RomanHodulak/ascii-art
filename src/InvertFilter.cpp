#include <vector>
#include "InvertFilter.h"

Pixel InvertFilter::apply(const Pixel & pixel) const {
	std::vector<unsigned short> channels(pixel.getChannelsCount());

	for (size_t i = 0; i < pixel.getChannelsCount(); ++i) {
		channels[i] = (unsigned short) -(pixel.getChannel(i) - 255);
	}

	return Pixel(channels.begin(), channels.end());
}
