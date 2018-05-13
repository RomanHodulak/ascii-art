#ifndef ASCII_ART_STATICIMAGESOURCE_H
#define ASCII_ART_STATICIMAGESOURCE_H

#include "ImageSource.h"

/**
 * Abstract image source for static image formats.
 */
class StaticImageSource : public ImageSource {
protected:

	/**
	 * Gets count of frames in the image.
	 *
	 * @return Since this is a static image format, returns 1.
	 */
	size_t getFramesCountTotal() const override;

	/**
	 * Gets frame at given index.
	 *
	 * @param index Frame index. Only valid index is 0.
	 * @return Frame at given index.
	 */
	Frame & getFrameAt(size_t index) const override;

	/**
	 * Gets the image frame.
	 *
	 * @return Image frame.
	 */
	virtual Frame & getFrame() const = 0;
};

#endif //ASCII_ART_STATICIMAGESOURCE_H
