#ifndef ASCII_ART_BMPIMAGESOURCE_H
#define ASCII_ART_BMPIMAGESOURCE_H

#include <string>
#include <fstream>
#include <cinttypes>
#include "StaticImageSource.h"

using namespace std;

/**
 * Loads BMP files.
 */
class BmpImageSource : public StaticImageSource {
private:

	/** File containing source BMP image. */
	ifstream sourceFile;

	Frame * frame = nullptr;

protected:

	/**
	 * Gets BMP image as a frame.
	 *
	 * @return Frame at given index.
	 */
	Frame & getFrame() override;

public:

	/**
	 * Constructs BMP image source from file.
	 *
	 * @param filename File name of the BMP.
	 */
	explicit BmpImageSource(const string & filename);
};

#endif //ASCII_ART_BMPIMAGESOURCE_H
