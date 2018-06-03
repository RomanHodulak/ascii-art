#include <cstdlib>

template <typename Iterator>
Frame::Frame(size_t width, size_t height, Iterator pixelsBegin, Iterator pixelsEnd) : width(width), height(height) {
	this->pixels = new Pixel ** [height];

	for (size_t i = 0; i < height; ++i) {
		this->pixels[i] = new Pixel * [width];

		for (size_t j = 0; j < width; ++j) {
			if (pixelsBegin == pixelsEnd) {
				throw std::exception();
			}

			this->pixels[i][j] = new Pixel(* pixelsBegin);
			++pixelsBegin;
		}
	}
}
