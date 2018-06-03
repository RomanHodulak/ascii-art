#include "ImageSource.h"

using namespace std;

size_t ImageSource::getFramesCount() const {
	return this->indices.size();
}

Frame & ImageSource::getFrame(size_t index) {
	if (index >= this->indices.size()) {
		throw exception();
	}

	return this->getFrameAt(this->indices[index]);
}

void ImageSource::skipFrame(size_t index) {
	if (index >= this->indices.size()) {
		throw exception();
	}

	this->indices.erase(this->indices.begin() + index);
}

void ImageSource::swapFrames(size_t first, size_t second) {
	if (max(first, second) >= this->indices.size()) {
		throw exception();
	}

	this->indices[first] = second;
	this->indices[second] = first;
}

ImageSource::ImageSource(size_t framesCount) : framesCount(framesCount) {
	this->indices.reserve(framesCount);

	for (size_t i = 0; i < framesCount; ++i) {
		this->indices.push_back(i);
	}
}

size_t ImageSource::getFramesCountTotal() const {
	return this->framesCount;
}
