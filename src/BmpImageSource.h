#ifndef ASCII_ART_BMPIMAGESOURCE_H
#define ASCII_ART_BMPIMAGESOURCE_H

#include <string>
#include "StaticImageSource.h"

using namespace std;

class BmpImageSource : public StaticImageSource {
protected:

	/**
	 * Constructs BMP image source from file.
	 *
	 * @param filename File name of the BMP.
	 */
	explicit BmpImageSource(const string & filename);

	/**
	 * Gets BMP image as a frame.
	 *
	 * @return Frame at given index.
	 */
	Frame & getFrame() const override;
};

#endif //ASCII_ART_BMPIMAGESOURCE_H
