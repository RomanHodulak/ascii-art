#include "FilterMenuControl.h"

FilterMenuControl::FilterMenuControl(const Rectangle & rect) : Control(rect) {
}

Control * FilterMenuControl::clone() const {
	return new FilterMenuControl(* this);
}

std::ostream & FilterMenuControl::print(std::ostream & out) {
	out << "╔";
	for (size_t i = 2; i < this->rect.width; ++i) {
		out << "═";
	}
	out << "╗" << std::endl;

	std::string line = "║ Choose filter to add: ";
	out << line;

	for (size_t k = line.length() - 1; k < this->rect.width; ++k) {
		out << ' ';
	}
	out << "║" << std::endl;

	for (size_t i = 0; i < this->items.size(); ++i) {
		const Item & item = this->items[i];
		size_t charsPrinted = 6 + item.first.length();

		out << "║ "
			<< (this->selectedIndex == i ? "→ " : "  ")
			<< item.first
			<< (this->selectedIndex == i ? " ←" : "  ");

		for (size_t j = charsPrinted + 1; j < this->rect.width; ++j) {
			out << ' ';
		}

		out << "║" << std::endl;
	}

	out << "╚";
	for (size_t i = 2; i < this->rect.width; ++i) {
		out << "═";
	}
	out << "╝" << std::endl;

	return out;
}

void FilterMenuControl::addItem(const std::string & title, std::function<void()> onEnter) {
	this->items.emplace_back(std::make_pair(title, onEnter));
}

void FilterMenuControl::up() {
	if (this->selectedIndex-- == 0) {
		this->selectedIndex = this->items.size() - 1;
	}
}

void FilterMenuControl::down() {
	if (++this->selectedIndex == this->items.size()) {
		this->selectedIndex = 0;
	}
}

void FilterMenuControl::accept() {
	this->items[this->selectedIndex].second();
}
