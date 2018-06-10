#include <vector>
#include "InvertFilter.h"

Pixel InvertFilter::apply(const Pixel & pixel) const {
	return pixel * -1.0;
}

std::string InvertFilter::getName() const {
	return "Invert";
}

Filter * InvertFilter::clone() const {
	return new InvertFilter(* this);
}
