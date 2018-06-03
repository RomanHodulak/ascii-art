#include <fstream>
#include "AsciiPrinter.h"

using namespace std;

AsciiPrinter::AsciiPrinter(const string & source) {
	ifstream sourceStream(source);

	while (sourceStream) {
		int code;
		char ch;

		sourceStream >> code;
		sourceStream >> ch;

		if (code > 255 || code < 0) {
			throw exception();
		}

		this->characterMap[code] = ch;
	}

	sourceStream.close();
}

ostream & AsciiPrinter::print(ostream & output, const Pixel & pixel) const {
	if (pixel.getChannelsCount() != 1) {
		throw exception();
	}

	return output << this->characterMap.at(pixel.getChannel(0));
}
