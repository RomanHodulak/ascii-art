#ifndef ASCII_ART_MULTIIMAGESOURCE_H
#define ASCII_ART_MULTIIMAGESOURCE_H

#include "ImageSource.h"

/**
 * Combines multiple image sources into one. Uses frames from all of its child sources, behaving like a single image
 * source on the outside.
 */
class MultiImageSource : public ImageSource {
private:

	std::vector<ImageSource *> sources;

	/**
	 * Releases allocated resources.
	 */
	void dispose();

	/**
	 * Copies data from another instance.
	 */
	void copyFrom(const MultiImageSource & pixel);

public:

	MultiImageSource(const MultiImageSource & source);

	MultiImageSource & operator=(const MultiImageSource & source);

	~MultiImageSource();

	/**
	 * Gets frame at given index, searching over all of the image sources.
	 *
	 * @param index Frame index.
	 * @return Frame at given index.
	 */
	Frame & getFrame(size_t index) override;

	/**
	 * Pushes image source to the end of the queue.
	 *
	 * @tparam Type that inherits class ImageSource.
	 * @param filter Image source to push.
	 */
	template <typename T>
	void pushSource(const T & source);

	/**
	 * Swaps order of the image sources by given indices.
	 *
	 * @param first Image source that gets moved to second index.
	 * @param second Image source that gets moved to first index.
	 */
	void swapSources(size_t first, size_t second);

	/**
	 * Removes image source by given index.
	 *
	 * @param index Index of the image source to remove.
	 */
	void removeSource(size_t index);

	/**
	 * Gets count of sources.
	 *
	 * @return Sources count.
	 */
	size_t getSourcesCount() const;

	/**
	 * Gets image source by index.
	 *
	 * @param index Index of the image source.
	 * @return Image source instance pointer.
	 */
	ImageSource * getSourceAt(size_t index) const;

	ImageSource * clone() const override;

public:

	MultiImageSource();
};

#include "MultiImageSource.tpp"

#endif //ASCII_ART_MULTIIMAGESOURCE_H
