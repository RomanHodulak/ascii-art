#include "FilterPanelControl.h"

using namespace std;

FilterPanelControl::FilterPanelControl(const Rectangle & rect)
	: Control(rect) {
}

Control * FilterPanelControl::clone() const {
	return new FilterPanelControl(* this);
}

std::ostream & FilterPanelControl::print(std::ostream & out) {
	out << " Filters" << endl;

	for (int i = 0; i < this->rect.width; ++i) {
		out << "═";
	}
	out << endl;

	for (size_t i = 0; i < this->filterMenuItems.size(); ++i) {
		FilterMenuItem & item = this->filterMenuItems[i];

		if (i == this->selectedIndex) {
			if (this->editMode) {
				out << " Set";
			}
			else {
				out << " → " << item.title;
			}
		}
		else {
			out << ' ' << item.title;
		}

		if (item.getter != nullptr) {
			out << ": " << std::to_string(item.getter(this->filter.getFilterAt(i))).substr(0, 5);
		}

		if (i == this->selectedIndex && !this->editMode) {
			out << " ←     " << endl;
		}
		else {
			out << "             " << endl;
		}
	}

	for (int i = 0; i < this->rect.width; ++i) {
		out << ' ';
	}

	return out;
}

void FilterPanelControl::up() {
	if (this->selectedIndex-- == 0) {
		this->selectedIndex = this->filterMenuItems.size() - 1;
	}
}

void FilterPanelControl::down() {
	++this->selectedIndex;
	this->selectedIndex %= this->filterMenuItems.size();
}

const MultiFilter & FilterPanelControl::getFilter() const {
	return this->filter;
}

void FilterPanelControl::deleteSelected() {
	if (this->selectedIndex > 0) {
		this->filter.removeFilter(this->selectedIndex);
		this->filterMenuItems.erase(this->filterMenuItems.begin() + this->selectedIndex);

		if (this->selectedIndex >= this->filter.getFilterCount()) {
			this->selectedIndex = this->filter.getFilterCount() - 1;
		}
	}
}

bool FilterPanelControl::editSelected() {
	if (this->editMode) return false;

	if (this->filterMenuItems[this->selectedIndex].setter != nullptr) {
		this->editMode = true;
	}

	return this->editMode;
}

void FilterPanelControl::leaveEditMode() {
	this->editMode = false;
}

void FilterPanelControl::editInc() {
	double val = this->filterMenuItems[this->selectedIndex].getter(this->filter.getFilterAt(this->selectedIndex));
	this->filterMenuItems[this->selectedIndex].setter(this->filter.getFilterAt(this->selectedIndex), val + 0.1);
}

void FilterPanelControl::editDec() {
	double val = this->filterMenuItems[this->selectedIndex].getter(this->filter.getFilterAt(this->selectedIndex));
	this->filterMenuItems[this->selectedIndex].setter(this->filter.getFilterAt(this->selectedIndex), val - 0.1);
}
