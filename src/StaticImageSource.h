#ifndef ASCII_ART_STATICIMAGESOURCE_H
#define ASCII_ART_STATICIMAGESOURCE_H

#include "ImageSource.h"

/**
 * Abstract image source for static image formats.
 */
class StaticImageSource : public ImageSource {
protected:

	StaticImageSource();

	/**
	 * Gets frame at given index.
	 *
	 * @param index Frame index. For a static image, only valid index is 0.
	 * @return Frame at given index.
	 */
	Frame & getFrame(size_t index) override;

	/**
	 * Gets the image frame.
	 *
	 * @return Image frame.
	 */
	virtual Frame & getFrame() = 0;
};

#endif //ASCII_ART_STATICIMAGESOURCE_H
