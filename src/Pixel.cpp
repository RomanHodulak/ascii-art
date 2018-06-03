#include <exception>
#include "Pixel.h"

using namespace std;

Pixel::Pixel(initializer_list<unsigned short> values) {
	this->channelCount = values.size();
	this->channels = new unsigned short[this->channelCount];

	for (size_t i = 0; i < this->channelCount; ++i) {
		this->channels[i] = * (values.begin() + i);
	}
}

Pixel::~Pixel() {
	delete [] this->channels;
}

size_t Pixel::getChannelsCount() const {
	return this->channelCount;
}

unsigned short Pixel::getChannel(size_t index) const {
	if (index >= this->channelCount) {
		throw exception();
	}

	return this->channels[index];
}

Pixel Pixel::operator*(double multiplier) const {
	Pixel multipliedPixel(* this);

	for (size_t i = 0; i < multipliedPixel.channelCount; ++i) {
		multipliedPixel.channels[i] *= multiplier;
	}

	return multipliedPixel;
}

Pixel::Pixel(const Pixel & pixel) {
	this->channelCount = pixel.channelCount;
	this->channels = new unsigned short[this->channelCount];

	for (size_t i = 0; i < this->channelCount; ++i) {
		this->channels[i] = pixel.channels[i];
	}
}

Pixel & Pixel::operator=(const Pixel & pixel) {
	if (this != &pixel) {
		this->channelCount = pixel.channelCount;
		this->channels = new unsigned short[this->channelCount];

		for (size_t i = 0; i < this->channelCount; ++i) {
			this->channels[i] = pixel.channels[i];
		}
	}

	return * this;
}
