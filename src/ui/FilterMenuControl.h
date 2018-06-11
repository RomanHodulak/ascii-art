#ifndef ASCII_ART_FILTERDIALOG_H
#define ASCII_ART_FILTERDIALOG_H

#include <vector>
#include <functional>
#include "Control.h"

/**
 * Small window with a list-like menu with selectable items, each having an action callback on them that can be
 * invoked with a call to accept method.
 */
class FilterMenuControl : public Control {
private:

	/** Item type, containing title and callback to invoke when item is accepted. */
	typedef std::pair<std::string, std::function<void()>> Item;

	/** All the menu items. */
	std::vector<Item> items;

	/** Currently selected item's index. */
	size_t selectedIndex = 0;

public:

	explicit FilterMenuControl(const Rectangle & rect);

	Control * clone() const override;

	std::ostream & print(std::ostream & out) override;

	/**
	 * Adds item into the list.
	 *
	 * @param title Title to display in the window.
	 * @param onAccept Callback to invoke on accept call.
	 */
	void addItem(const std::string & title, std::function<void()> onAccept);

	/**
	 * Moves currently selected menu item up by one.
	 */
	void up();

	/**
	 * Moves currently selected menu item down by one.
	 */
	void down();

	/**
	 * Calls onAccept action on the currently selected item.
	 */
	void accept();
};

#endif //ASCII_ART_FILTERDIALOG_H
