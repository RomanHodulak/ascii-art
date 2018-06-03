#include "MultiFilter.h"

using namespace std;

Pixel MultiFilter::apply(const Pixel & pixel) const {
	Pixel filtered(pixel);

	for (Filter * f : this->filters) {
		filtered = f->apply(filtered);
	}

	return filtered;
}

void MultiFilter::swapFilters(size_t first, size_t second) {
	if (max(first, second) >= this->filters.size()) {
		throw exception();
	}

	Filter * tmp = this->filters.at(first);
	this->filters[first] = this->filters.at(second);
	this->filters[second] = tmp;
}

void MultiFilter::removeFilter(size_t index) {
	if (this->filters.size() >= index) {
		throw exception();
	}

	this->filters.erase(this->filters.begin() + index);
}

size_t MultiFilter::getFilterCount() const {
	return this->filters.size();
}

Filter * MultiFilter::getFilterAt(size_t index) const {
	if (this->filters.size() >= index) {
		throw exception();
	}

	return this->filters.at(index);
}
