#include "MultiImageSource.h"

using namespace std;

MultiImageSource::MultiImageSource() : ImageSource(0) {
}

size_t MultiImageSource::getSourcesCount() const {
	return this->sources.size();
}

ImageSource * MultiImageSource::getSourceAt(size_t index) const {
	if (index >= this->sources.size()) {
		throw exception();
	}

	return this->sources[index];
}

void MultiImageSource::removeSource(size_t index) {
	if (index >= this->sources.size()) {
		throw exception();
	}

	this->sources.erase(this->sources.begin() + index);
}

void MultiImageSource::swapSources(size_t first, size_t second) {
	if (max(first, second) >= this->sources.size()) {
		throw exception();
	}

	ImageSource * tmp = this->sources.at(first);
	this->sources[first] = this->sources.at(second);
	this->sources[second] = tmp;
}

Frame & MultiImageSource::getFrame(size_t index) {
	size_t counter = 0;

	for (auto & source : this->sources) {
		for (size_t j = 0; j < source->getFramesCount(); ++j) {
			if (counter == index) {
				return source->getFrame(j);
			}

			++counter;
		}
	}

	throw exception();
}

void MultiImageSource::dispose() {
	for (ImageSource * source : this->sources) {
		delete source;
	}
}

void MultiImageSource::copyFrom(const MultiImageSource & pixel) {
	this->sources.clear();
	for (ImageSource * source : pixel.sources) {
		this->sources.push_back(source->clone());
	}
}

ImageSource * MultiImageSource::clone() const {
	return new MultiImageSource(* this);
}

MultiImageSource::MultiImageSource(const MultiImageSource & source) : ImageSource(source) {
	this->copyFrom(source);
}

MultiImageSource & MultiImageSource::operator=(const MultiImageSource & source) {
	if (this != &source) {
		this->dispose();
		this->copyFrom(source);
	}

	return * this;
}

MultiImageSource::~MultiImageSource() {
	this->dispose();
}
