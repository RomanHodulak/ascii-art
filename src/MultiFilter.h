#ifndef ASCII_ART_MULTIFILTER_H
#define ASCII_ART_MULTIFILTER_H

#include <vector>
#include "Filter.h"

/**
 * Combines several filters, applying them one by one in a queue.
 */
class MultiFilter : public Filter {
private:

	/** Filters applied by this multi filter. */
	std::vector<Filter *> filters;

	/**
	 * Releases allocated resources.
	 */
	void dispose();

	/**
	 * Copies data from another instance.
	 */
	void copyFrom(const MultiFilter & pixel);

public:

	MultiFilter() = default;

	MultiFilter(const MultiFilter & filter);

	MultiFilter & operator=(const MultiFilter & filter);

	~MultiFilter();

	/**
	 * Applies all of the filters one by one to a copy of given pixel and returns the result.
	 *
	 * @param pixel Pixel to apply all of the filters to.
	 * @return Modified pixel.
	 */
	Pixel apply(const Pixel & pixel) const override;

	/**
	 * Pushes filter to the end of the queue.
	 *
	 * @tparam Type that inherits class Filter.
	 * @param filter Filter to push.
	 */
	template <typename T>
	void pushFilter(const T & filter);

	/**
	 * Swaps order of the filters by given indices.
	 *
	 * @param first Filter that gets moved to second index.
	 * @param second Filter that gets moved to first index.
	 */
	void swapFilters(size_t first, size_t second);

	/**
	 * Removes filter by given index.
	 *
	 * @param index Index of the filter to remove.
	 */
	void removeFilter(size_t index);

	/**
	 * Gets count of filters.
	 *
	 * @return Filter count.
	 */
	size_t getFilterCount() const;

	/**
	 * Gets filter by index.
	 *
	 * @param index Index of the filter.
	 * @return Filter instance pointer.
	 */
	Filter * getFilterAt(size_t index) const;

	std::string getName() const override;

	Filter * clone() const override;
};

#include "MultiFilter.tpp"

#endif //ASCII_ART_MULTIFILTER_H
