template <typename T>
void MultiFilter::pushFilter(const T & filter) {
	this->filters.push_back(new T(filter));
}
