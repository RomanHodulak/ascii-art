template <typename T>
void MultiImageSource::pushSource(const T & source) {
	this->framesCount += source.getFramesCount();
	this->sources.push_back(new T(source));
}
