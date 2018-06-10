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
protected:

	/** Total frames count. */
	size_t framesCount;

	/**
	 * @param framesCount Total count of frames in this image (1 for static images).
	 */
	explicit ImageSource(size_t framesCount);

public:

	virtual ~ImageSource() = default;

	/**
	 * Gets count of frames.
	 *
	 * @return Count of frames in this image.
	 */
	size_t getFramesCount() const;

	/**
	 * Gets frame at given index. Ignores frame skipping and swapping.
	 *
	 * @param index Frame index.
	 * @return Frame at given index.
	 */
	virtual Frame & getFrame(size_t index) = 0;

	virtual ImageSource * clone() const = 0;
};

#endif //ASCII_ART_ANIMATION_H
