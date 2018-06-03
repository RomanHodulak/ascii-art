#include "BrightnessFilter.h"

void BrightnessFilter::setBrightness(double brightness) {
	this->brightness = brightness;
}

double BrightnessFilter::getBrightness() {
	return this->brightness;
}

Pixel BrightnessFilter::apply(const Pixel & pixel) const {
	return pixel * this->brightness;
}
