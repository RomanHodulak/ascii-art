#include "ImageSource.h"

using namespace std;

size_t ImageSource::getFramesCount() const {
	return this->framesCount;
}

ImageSource::ImageSource(size_t framesCount) : framesCount(framesCount) {
}
