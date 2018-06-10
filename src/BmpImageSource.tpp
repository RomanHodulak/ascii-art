#include <cstring>

template <typename Callable>
void BmpImageSource::FrameData::loadFrame(Callable loader) {
	std::ifstream fileStream(this->filename, std::ios_base::binary);

	if (!fileStream) {
		throw InvalidFileException("BMP", this->filename, strerror(errno));
	}

	this->frame = loader(fileStream);
}
