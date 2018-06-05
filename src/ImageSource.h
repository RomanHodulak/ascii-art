#ifndef ASCII_ART_ANIMATION_H
#define ASCII_ART_ANIMATION_H

#include <cstdlib>
#include <vector>
#include "Frame.h"

/**
 * Abstract image source. Image consists of one (static image) or several frames (animation). This class implements
 * skipping and swapping frames, although implementors do not need to worry about it. Conversion is done in this class
 * while implementors should return frames in the original order and count.
 */
class ImageSource {
private:

	/** Total frames count, including the skipped ones. */
	size_t framesCount;

	/** Maps outside indices (counts swaps and exclusions) to actual indices. */
	std::vector<size_t> indices;

protected:

	/**
	 * @param framesCount Total count of frames in this image (1 for static images).
	 */
	explicit ImageSource(size_t framesCount);

	void addIndices(size_t count);

public:

	/**
	 * Gets count of frames, including the skipped ones.
	 *
	 * @return Count of frames in this image.
	 */
	size_t getFramesCountTotal() const;

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
	Frame & getFrame(size_t index);

	/**
	 * Gets frame at given index. Ignores frame skipping and swapping.
	 *
	 * @param index Frame index.
	 * @return Frame at given index.
	 */
	virtual Frame & getFrameAt(size_t index) = 0;

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
