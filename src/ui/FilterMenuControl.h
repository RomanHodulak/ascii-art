#ifndef ASCII_ART_FILTERDIALOG_H
#define ASCII_ART_FILTERDIALOG_H

#include <vector>
#include <functional>
#include "Control.h"

class FilterMenuControl : public Control {
private:

	typedef std::pair<std::string, std::function<void()>> Item;

	std::vector<Item> items;
	size_t selectedIndex = 0;

public:

	explicit FilterMenuControl(const Rectangle & rect);

	Control * clone() const override;

	std::ostream & print(std::ostream & out) override;

	void addItem(const std::string & title, std::function<void()> onEnter);

	void up();

	void down();

	void accept();
};

#endif //ASCII_ART_FILTERDIALOG_H
