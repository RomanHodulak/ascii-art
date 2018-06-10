#ifndef ASCII_ART_PIXEL_H
#define ASCII_ART_PIXEL_H

#include <cinttypes>
#include <cstdlib>
#include <initializer_list>

/**
 * Collection of color channels.
 */
class Pixel {
private:

	typedef unsigned short channel;
	static const channel CHANNEL_MAX = 255;
	size_t channelCount;
	channel * channels;

	/**
	 * Releases allocated resources.
	 */
	void dispose();

	/**
	 * Copies data from another instance.
	 */
	void copyFrom(const Pixel & pixel);

public:

	/**
	 * Constructs pixel with given channels.
	 *
	 * @param values Channels of the pixel.
	 */
	Pixel(std::initializer_list<channel> values);

	/**
	 * Constructs pixel with given channels.
	 *
	 * @tparam Iterator Forward Iterator type.
	 * @param channelsBegin Iterator that points to the first channel.
	 * @param channelsEnd Past-the-end iterator of the channels.
	 */
	template <typename Iterator>
	Pixel(Iterator channelsBegin, Iterator channelsEnd);

	/**
	 * Constructs pixel with a copy of channels of the given pixel.
	 *
	 * @param pixel Pixel to copy from.
	 */
	Pixel(const Pixel & pixel);

	/**
	 * Deep-copies channels of the given pixel.
	 *
	 * @param pixel Pixel to copy from.
	 * @return This instance reference.
	 */
	Pixel & operator=(const Pixel & pixel);

	/**
	 * Releases allocated resources.
	 */
	~Pixel();

	/**
	 * @return Count of channels in this pixel.
	 */
	size_t getChannelsCount() const;

	/**
	 * @param index Channel index.
	 * @return Channel at given index.
	 */
	channel getChannel(size_t index) const;

	/**
	 * Multiplies pixel channels with given multiplier.
	 *
	 * @param multiplier Value to multiply each pixel with.
	 * @return Multiplied pixel.
	 */
	Pixel operator*(double multiplier) const;
};

#include "Pixel.tpp"

#endif //ASCII_ART_PIXEL_H
