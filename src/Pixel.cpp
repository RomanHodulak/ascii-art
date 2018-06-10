#include <exception>
#include "Pixel.h"

using namespace std;

Pixel::Pixel(initializer_list<channel> values) {
	this->channelCount = values.size();
	this->channels = new channel[this->channelCount];

	for (size_t i = 0; i < this->channelCount; ++i) {
		this->channels[i] = * (values.begin() + i);
	}
}

Pixel::~Pixel() {
	this->dispose();
}

size_t Pixel::getChannelsCount() const {
	return this->channelCount;
}

Pixel::channel Pixel::getChannel(size_t index) const {
	if (index >= this->channelCount) {
		throw exception();
	}

	return this->channels[index];
}

Pixel Pixel::operator*(double multiplier) const {
	Pixel multipliedPixel(* this);

	for (size_t i = 0; i < multipliedPixel.channelCount; ++i) {
		if (multiplier < 0) {
			// Inversion
			multipliedPixel.channels[i] = CHANNEL_MAX - multipliedPixel.channels[i];
			multipliedPixel.channels[i] *= -multiplier;
		}
		else {
			multipliedPixel.channels[i] *= multiplier;
		}

		if (multipliedPixel.channels[i] > CHANNEL_MAX) {
			multipliedPixel.channels[i] = CHANNEL_MAX;
		}
	}

	return multipliedPixel;
}

Pixel::Pixel(const Pixel & pixel) {
	this->copyFrom(pixel);
}

Pixel & Pixel::operator=(const Pixel & pixel) {
	if (this != &pixel) {
		this->dispose();
		this->copyFrom(pixel);
	}

	return * this;
}

void Pixel::dispose() {
	delete [] this->channels;
}

void Pixel::copyFrom(const Pixel & pixel) {
	this->channelCount = pixel.channelCount;
	this->channels = new channel[this->channelCount];

	for (size_t i = 0; i < this->channelCount; ++i) {
		this->channels[i] = pixel.channels[i];
	}
}
