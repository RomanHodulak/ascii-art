#ifndef ASCII_ART_FRAME_H
#define ASCII_ART_FRAME_H

#include <cstdio>
#include "AsciiPrinter.h"

/**
 * Contains pixel matrix stored in memory.
 */
class Frame {
private:

	Pixel *** pixels;
	size_t width;
	size_t height;

	/**
	 * Deep-copies data from other frame.
	 *
	 * @param frame Frame to copy from.
	 */
	void copyFrom(const Frame & frame);

	/**
	 * Releases allocated resources.
	 */
	void dispose();

public:

	/**
	 * Creates new instance with given dimensions and buffer.
	 *
	 * @tparam Iterator Forward iterator of pixel buffer.
	 * @param width Width of the frame in pixels.
	 * @param height Height of the frame in pixels.
	 * @param pixelsBegin Iterator pointing to first pixel in a buffer.
	 * @param pixelsEnd Past-the-end iterator of the pixel buffer.
	 */
	template <typename Iterator>
	Frame(size_t width, size_t height, Iterator pixelsBegin, Iterator pixelsEnd);

	/**
	 * Creates new instance with data copied from other frame.
	 *
	 * @param frame Frame to copy from.
	 */
	Frame(const Frame & frame);

	/**
	 * Copies data from other frame into this one.
	 *
	 * @param frame Frame to copy from.
	 * @return This instance reference.
	 */
	Frame & operator=(const Frame & frame);

	/**
	 * Releases allocated resources.
	 */
	~Frame();

	/**
	 * Prints the frame.
	 *
	 * @param output Output to print the frame to.
	 * @param printer Printer to print the frame with.
	 * @param filter Filter that gets applied to every pixel of the frame.
	 */
	std::ostream & print(std::ostream & output, const AsciiPrinter & printer, const Filter & filter) const;
};

#include "Frame.tpp"

#endif //ASCII_ART_FRAME_H
