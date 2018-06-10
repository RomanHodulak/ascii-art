#ifndef ASCII_ART_FILTERPANELCONTROL_H
#define ASCII_ART_FILTERPANELCONTROL_H

#include "Control.h"
#include "../Filter.h"
#include "../GreyscaleFilter.h"
#include "../InvertFilter.h"
#include "../BrightnessFilter.h"
#include "../MultiFilter.h"
#include <functional>

class FilterPanelControl : public Control {
private:

	struct FilterMenuItem {
		std::string title;
		std::function<double(Filter *)> getter;
		std::function<void(Filter *, double)> setter;
	};

	size_t selectedIndex = 0;
	std::vector<FilterMenuItem> filterMenuItems;
	MultiFilter filter;
	bool editMode = false;

public:

	explicit FilterPanelControl(const Rectangle & rect);

	Control * clone() const override;

	std::ostream & print(std::ostream & out) override;

	template <typename T>
	void addFilterItem(const std::string & title, const T & filter);

	template <typename T>
	void addFilterItem(
		const std::string & title,
		const T & filter,
		double (T::* getter)(),
		void (T::* setter)(double)
	);

	void up();

	void down();

	void deleteSelected();

	bool editSelected();

	const MultiFilter & getFilter() const;

	void editInc();

	void editDec();

	void leaveEditMode();
};

#include "FilterPanelControl.tpp"

#endif //ASCII_ART_FILTERPANELCONTROL_H
