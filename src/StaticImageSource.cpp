#include <bits/exception.h>
#include "StaticImageSource.h"

using namespace std;

StaticImageSource::StaticImageSource() : ImageSource(1) {
}

Frame & StaticImageSource::getFrame(size_t index) {
	if (index != 0) {
		throw exception();
	}

	return this->getFrame();
}
