#include <fstream>
#include "AsciiPrinter.h"

using namespace std;

AsciiPrinter::AsciiPrinter(const string & source) {
	ifstream sourceStream(source);

	int min = 256;
	char minChar = 0;

	// Load map from file
	while (sourceStream) {
		int code;
		char ch;

		sourceStream >> code;
		sourceStream >> ch;

		if (code > 255 || code < 0) {
			throw exception();
		}

		if (code < min) {
			min = code;
			minChar = ch;
		}

		this->characterMap[code] = ch;
	}

	sourceStream.close();

	// Fill in "holes"
	for (char & ch : this->characterMap) {
		if (ch == 0) {
			ch = minChar;
		}
		else {
			minChar = ch;
		}
	}
}

ostream & AsciiPrinter::print(ostream & output, const Pixel & pixel) const {
	if (pixel.getChannelsCount() != 1) {
		throw exception();
	}

	return output << this->characterMap[pixel.getChannel(0)];
}
