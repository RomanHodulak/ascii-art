#include <bits/ios_base.h>
#include "BmpImageSource.h"

#define BI_RGB 0

using namespace std;

BmpImageSource::BmpImageSource(const string & filename) : StaticImageSource() {
	this->data = new FrameData(filename);
}

Frame & BmpImageSource::getFrame() {
	if (this->data->frame == nullptr) {
		this->data->loadFrame([this](istream & sourceStream)->Frame *{
			return this->loadFrame(sourceStream);
		});
	}

	return * this->data->frame;
}

BmpImageSource::BmpImageSource(const BmpImageSource & source) : StaticImageSource(source) {
	this->attach(source.data);
}

BmpImageSource & BmpImageSource::operator=(const BmpImageSource & source) {
	StaticImageSource::operator=(source);

	if (this->data != source.data) {
		this->detach();
		this->attach(source.data);
	}

	return * this;
}

BmpImageSource::~BmpImageSource() {
	this->detach();
}

void BmpImageSource::attach(BmpImageSource::FrameData * data) {
	this->data = data;
	++this->data->refCnt;
}

void BmpImageSource::detach() {
	if (--this->data->refCnt == 0) {
		delete this->data;
		this->data = nullptr;
	}
}

Frame * BmpImageSource::loadFrame(istream & sourceStream) const {
	struct BmpHeader {
		uint16_t magic; // Must equal to "BM" in ASCII to be BMP file
		uint32_t size;
		uint32_t reserved;
		uint32_t offset;
		uint32_t headerSize;
		uint32_t width;
		uint32_t height;
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

	sourceStream.seekg(0);
	sourceStream.read((char *) & header.magic, 2);
	sourceStream.read((char *) & header.size, 4);
	sourceStream.read((char *) & header.reserved, 4);
	sourceStream.read((char *) & header.offset, 4);
	sourceStream.read((char *) & header.headerSize, 4);
	sourceStream.read((char *) & header.width, 4);
	sourceStream.read((char *) & header.height, 4);
	sourceStream.read((char *) & header.colorPlanes, 2);
	sourceStream.read((char *) & header.bitsPerPixel, 2);
	sourceStream.read((char *) & header.compression, 4);
	sourceStream.read((char *) & header.imageSize, 4);
	sourceStream.read((char *) & header.ppmHorizontal, 4);
	sourceStream.read((char *) & header.ppmVertical, 4);
	sourceStream.read((char *) & header.colorsCount, 4);
	sourceStream.read((char *) & header.importantColors, 4);

	if (header.magic != 0x4D42) {
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
	sourceStream.seekg(header.offset);

	for (size_t i = 0; i < pixelCount; ++i) {
		unsigned char channels [3];
		sourceStream.read((char *) &channels, 3);

		buffer.emplace_back(Pixel(channels, channels + 3));
	}

	return new Frame(header.width, header.height, buffer.begin(), buffer.end());
}

BmpImageSource::FrameData::FrameData(const string & filename) {
	this->refCnt = 1;
	this->filename = filename;
}

BmpImageSource::FrameData::~FrameData() {
	delete this->frame;
}
