#include <iterator>

template <typename Iterator>
Pixel::Pixel(Iterator channelsBegin, Iterator channelsEnd) {
	this->channelCount = (size_t) std::distance(channelsBegin, channelsEnd);
	this->channels = new unsigned short[this->channelCount];

	for (unsigned short * i = this->channels; channelsBegin != channelsEnd; ++channelsBegin) {
		* i++ = * channelsBegin;
	}
}
