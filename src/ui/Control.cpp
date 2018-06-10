#include "Control.h"

Control::Control(const Rectangle & rect) : rect(rect) {
}

std::ostream & operator<<(std::ostream & out, Control & control) {
	return control.print(out);
}

const Rectangle & Control::getRect() const {
	return this->rect;
}

Control::~Control() {
}
