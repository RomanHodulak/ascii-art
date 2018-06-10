#include <ncurses.h>
#include "Frame.h"

using namespace std;

ostream & Frame::print(ostream & output, const AsciiPrinter & printer, const Filter & filter) const {
	for (size_t i = 0; i < this->height; ++i) {
		for (size_t j = 0; j < this->width; ++j) {
			printer.print(output, filter.apply(* this->pixels[i][j]));
		}

		output << std::endl;
	}

	return output;
}

Frame::Frame(const Frame & frame) {
	this->copyFrom(frame);
}

Frame & Frame::operator=(const Frame & frame) {
	if (this != &frame) {
		this->dispose();
		this->copyFrom(frame);
	}

	return * this;
}

Frame::~Frame() {
	this->dispose();
}

void Frame::copyFrom(const Frame & frame) {
	this->width = frame.width;
	this->height = frame.height;
	this->pixels = new Pixel ** [height];

	for (size_t i = 0; i < height; ++i) {
		this->pixels[i] = new Pixel * [width];

		for (size_t j = 0; j < width; ++j) {
			this->pixels[i][j] = new Pixel(* frame.pixels[i][j]);
		}
	}
}

void Frame::dispose() {
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			delete this->pixels[i][j];
		}

		delete [] this->pixels[i];
	}

	delete [] this->pixels;
}
