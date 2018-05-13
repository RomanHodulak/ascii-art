#ifndef ASCII_ART_MULTIIMAGESOURCE_H
#define ASCII_ART_MULTIIMAGESOURCE_H

#include "ImageSource.h"

class MultiImageSource : public ImageSource {
protected:

	/**
	 * Gets count of frames in all image sources combined.
	 *
	 * @return Count of frames in this image.
	 */
	size_t getFramesCountTotal() const override;

	/**
	 * Gets frame at given index, aggregates all of the image sources.
	 *
	 * @param index Frame index.
	 * @return Frame at given index.
	 */
	Frame & getFrameAt(size_t index) const override;
};

#endif //ASCII_ART_MULTIIMAGESOURCE_H
