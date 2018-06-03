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

Frame & MultiImageSource::getFrameAt(size_t index) {
	size_t counter = 0;

	for (auto & source : this->sources) {
		for (size_t j = 0; j < source->getFramesCountTotal(); ++j) {
			if (counter == index) {
				return source->getFrameAt(j);
			}

			++counter;
		}
	}

	throw exception();
}
