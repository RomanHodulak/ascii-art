#ifndef ASCII_ART_ANIMATION_H
#define ASCII_ART_ANIMATION_H

#include <cstdlib>
#include "Frame.h"

/**
 * Abstract image source. Image consists of one (static image) or several frames (animation). This class implements
 * skipping and swapping frames, although implementors do not need to worry about it. Conversion is done in this class
 * while implementors should return frames in the original order and count.
 */
class ImageSource {
protected:

	/**
	 * Gets count of frames.
	 *
	 * @return Count of frames in this image.
	 */
	virtual size_t getFramesCountTotal() const = 0;

	/**
	 * Gets frame at given index.
	 *
	 * @param index Frame index.
	 * @return Frame at given index.
	 */
	virtual Frame & getFrameAt(size_t index) const = 0;

public:

	/**
	 * Gets count of frames, excluding the skipped frames.
	 *
	 * @return Count of frames in this image.
	 */
	size_t getFramesCount() const;

	/**
	 * Gets frame at given index. Excludes the skipped frames and respects frame swapping.
	 *
	 * @param index Frame index.
	 * @return Frame at given index.
	 */
	Frame & getFrame(size_t index) const;

	/**
	 * Sets frame that currently posses given index as skipped. Index then references the next frame and all following
	 * indices are decremented by one. If given index is last, then no frame will posses given index and others remain
	 * unchanged.
	 *
	 * @param index Index of the frame to skip.
	 */
	void skipFrame(size_t index);

	/**
	 * Swaps the two frames.
	 *
	 * @param first Frame to swap with the second.
	 * @param second Frame to swap with the first.
	 */
	void swapFrames(size_t first, size_t second);
};

#endif //ASCII_ART_ANIMATION_H
