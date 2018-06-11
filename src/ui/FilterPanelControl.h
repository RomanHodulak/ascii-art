#ifndef ASCII_ART_FILTERPANELCONTROL_H
#define ASCII_ART_FILTERPANELCONTROL_H

#include "Control.h"
#include "../Filter.h"
#include "../GreyscaleFilter.h"
#include "../InvertFilter.h"
#include "../BrightnessFilter.h"
#include "../MultiFilter.h"
#include <functional>

/**
 * Panel with a list of filters, featuring delete and edit actions.
 */
class FilterPanelControl : public Control {
private:

	struct FilterMenuItem {
		std::string title;
		std::function<double(Filter *)> getter;
		std::function<void(Filter *, double)> setter;
	};

	/** Currently selected menu item. */
	size_t selectedIndex = 0;

	/** All menu items. */
	std::vector<FilterMenuItem> filterMenuItems;

	/** Multi-filter that combines all the filters, displayed in the menu. */
	MultiFilter filter;

public:

	explicit FilterPanelControl(const Rectangle & rect);

	Control * clone() const override;

	std::ostream & print(std::ostream & out) override;

	/**
	 * Adds filter item to menu.
	 *
	 * @tparam T Filter type.
	 * @param title Filter name (menu item title).
	 * @param filter Filter reference.
	 */
	template <typename T>
	void addFilterItem(const std::string & title, const T & filter);

	/**
	 * Adds filter item to menu with a single editable field of type double.
	 *
	 * @tparam T Filter type.
	 * @param title Filter name (menu item title).
	 * @param filter Filter reference.
	 * @param getter Pointer to the getter member function of the editable value.
	 * @param setter Pointer to the setter member function of the editable value.
	 */
	template <typename T>
	void addFilterItem(
		const std::string & title,
		const T & filter,
		double (T::* getter)(),
		void (T::* setter)(double)
	);

	/**
	 * Gets the panel's multi-filter, usable for rendering.
	 *
	 * @return Filter that this panel displays and edits.
	 */
	const MultiFilter & getFilter() const;

	/**
	 * Moves currently selected menu item up by one.
	 */
	void up();

	/**
	 * Moves currently selected menu item down by one.
	 */
	void down();

	/**
	 * Deletes selected filter. Does not work on the first filter (Greyscale) as it is needed for rendering.
	 */
	void deleteSelected();

	/**
	 * Checks if currently selected filter is editable.
	 *
	 * @return TRUE if it can be edited, FALSE otherwise.
	 */
	bool isEditable();

	/**
	 * Increments currently edited value by 0.1, if it is editable.
	 */
	void editInc();

	/**
	 * Decrements currently selected value by 0.1, if it is editable.
	 */
	void editDec();
};

#include "FilterPanelControl.tpp"

#endif //ASCII_ART_FILTERPANELCONTROL_H
