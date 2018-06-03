template <typename T>
void MultiImageSource::pushSource(const T & source) {
	this->sources.push_back(new T(source));
}
