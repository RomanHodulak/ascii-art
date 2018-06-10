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

BrightnessFilter::BrightnessFilter(double brightness) {
	this->setBrightness(brightness);
}

std::string BrightnessFilter::getName() const {
	return "Brightness";
}

Filter * BrightnessFilter::clone() const {
	return new BrightnessFilter(* this);
}
