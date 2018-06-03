#include <bits/ios_base.h>
#include "BmpImageSource.h"

#define BI_RGB 0

using namespace std;

BmpImageSource::BmpImageSource(const string & filename)
	: StaticImageSource(), sourceFile(filename, ios_base::binary | ios_base::in) {
	if (!this->sourceFile) {
		throw exception(); // file not found
	}
}

Frame & BmpImageSource::getFrame() {
	if (this->frame == nullptr) {
		struct BmpHeader {
			uint16_t magic; // Must equal to "BM" in ASCII to be BMP file
			uint32_t size;
			uint32_t reserved;
			uint32_t offset;
			uint32_t headerSize;
			uint16_t width;
			uint16_t height;
			uint16_t colorPlanes;
			uint16_t bitsPerPixel;
			uint32_t compression;
			uint32_t imageSize;
			uint32_t ppmHorizontal; // Pixels per meter
			uint32_t ppmVertical; // Pixels per meter
			uint32_t colorsCount;
			uint32_t importantColors;
		};

		BmpHeader header{};

		this->sourceFile.read((char *) & header, sizeof(header));

		if (header.magic != 0x424D) {
			throw exception(); // Not a bmp file
		}
		if (header.compression != BI_RGB) {
			throw exception(); // Compression is not supported
		}
		if (header.bitsPerPixel != 24) {
			throw exception(); // Only RGB, 8bit per channel is supported
		}

		size_t pixelCount = header.width * header.height;
		vector<Pixel> buffer;
		this->sourceFile.seekg(header.offset);

		for (size_t i = 0; i < pixelCount; ++i) {
			unsigned short channels [3];
			channels[0] = i % 2 * 255;
			channels[1] = i % 4 * 255;
			channels[2] = i % 8 * 255;

			buffer.emplace_back(Pixel(channels, channels + 3));
		}

		this->frame = new Frame(header.width, header.height, buffer.begin(), buffer.end());
	}

	return * this->frame;
}
