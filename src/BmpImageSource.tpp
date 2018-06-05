template <typename Callable>
void BmpImageSource::FrameData::loadFrame(Callable loader) {
	std::ifstream fileStream(this->filename, std::ios_base::binary);
	if (!fileStream) {
		throw std::exception(); // file not found
	}
	this->frame = loader(fileStream);
}
