#ifndef ASCII_ART_PIXEL_H
#define ASCII_ART_PIXEL_H

#include <cinttypes>
#include <cstdlib>

class Pixel {
private:
	uint8_t * channels;

public:

	/**
	 * @return Count of channels in this pixel.
	 */
	size_t getChannelsCount() const;

	/**
	 * @param index Channel index.
	 * @return Channel at given index.
	 */
	uint8_t getChannel(size_t index) const;
};
#endif //ASCII_ART_PIXEL_H
