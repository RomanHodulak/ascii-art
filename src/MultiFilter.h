#ifndef ASCII_ART_MULTIFILTER_H
#define ASCII_ART_MULTIFILTER_H

#include <queue>
#include "Filter.h"

using namespace std;

/**
 * Combines several filters, applying them one by one in a queue.
 */
class MultiFilter : public Filter {
public:

	/**
	 * Applies all of the filters one by one to a copy of given pixel and returns the result.
	 *
	 * @param pixel Pixel to apply all of the filters to.
	 * @return Modified pixel.
	 */
	Pixel apply(const Pixel & pixel) const override;

	/**
	 * Pushes filter at the end of the queue.
	 *
	 * @param filter Filter to push.
	 */
	void pushFilter(Filter * filter);

	/**
	 * Gets mutable filter queue.
	 *
	 * @return Filter queue.
	 */
	queue<Filter *> & getFilters() const;
};

#endif //ASCII_ART_MULTIFILTER_H
