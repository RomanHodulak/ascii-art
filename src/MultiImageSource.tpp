template <typename T>
void MultiImageSource::pushSource(const T & source) {
	this->sources.push_back(new T(source));
	this->addIndices(source.getFramesCountTotal());
}
