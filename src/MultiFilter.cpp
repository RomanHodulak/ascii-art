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
	if (index >= this->filters.size()) {
		throw exception();
	}

	this->filters.erase(this->filters.begin() + index);
}

size_t MultiFilter::getFilterCount() const {
	return this->filters.size();
}

Filter * MultiFilter::getFilterAt(size_t index) const {
	if (index >= this->filters.size()) {
		throw exception();
	}

	return this->filters.at(index);
}

std::string MultiFilter::getName() const {
	return "Multi (" + this->getFilterCount() + ')';
}

MultiFilter::MultiFilter(const MultiFilter & filter) {
	this->copyFrom(filter);
}

MultiFilter & MultiFilter::operator=(const MultiFilter & filter) {
	if (this != & filter) {
		this->dispose();
		this->copyFrom(filter);
	}

	return * this;
}

MultiFilter::~MultiFilter() {
	this->dispose();
}

void MultiFilter::dispose() {
	for (Filter * filter : this->filters) {
		delete filter;
	}
}

void MultiFilter::copyFrom(const MultiFilter & pixel) {
	this->filters.clear();
	for (Filter * filter : this->filters) {
		this->filters.push_back(filter->clone());
	}
}

Filter * MultiFilter::clone() const {
	return new MultiFilter(* this);
}
