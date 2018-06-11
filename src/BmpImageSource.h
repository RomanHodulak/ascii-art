#ifndef ASCII_ART_BMPIMAGESOURCE_H
#define ASCII_ART_BMPIMAGESOURCE_H

#include <string>
#include <fstream>
#include <cinttypes>
#include <utility>
#include "StaticImageSource.h"
#include "InvalidFileException.h"

/**
 * Loads BMP files.
 */
class BmpImageSource : public StaticImageSource {
private:

	struct FrameData {
		int refCnt;
		std::string filename;
		Frame * frame = nullptr;

		explicit FrameData(const std::string & filename);

		~FrameData();

		template <typename Callable>
		void loadFrame(Callable loader);
	};

	FrameData * data = nullptr;

protected:

	/**
	 * Gets BMP image as a frame.
	 *
	 * @return Frame at given index.
	 */
	Frame & getFrame() override;

	Frame * loadFrame(std::istream & sourceStream) const;

	void attach(FrameData * data);

	void detach();

public:

	/**
	 * Constructs BMP image source from file.
	 *
	 * @param filename File name of the BMP.
	 */
	explicit BmpImageSource(const std::string & filename);

	BmpImageSource(const BmpImageSource & source);

	BmpImageSource & operator=(const BmpImageSource & source);

	~BmpImageSource() override;

	ImageSource * clone() const override;
};

#include "BmpImageSource.tpp"

#endif //ASCII_ART_BMPIMAGESOURCE_H
