#include <functional>

template <typename T>
void SidePanelControl::addFilterItem(
	const std::string & title,
	const T & filter
) {
	this->filterMenuItems.push_back({title, nullptr, nullptr});
	this->filter.pushFilter(filter);
}

template <typename T>
void SidePanelControl::addFilterItem(
	const std::string & title,
	const T & filter,
	double (T::* getter)(),
	void (T::* setter)(double)
) {
	this->filterMenuItems.push_back({
		title,
		[getter](Filter * instance) {
			return (* (T *) instance.*(getter))();
		},
		[setter](Filter * instance, double val) {
			return (* (T *) instance.*(setter))(val);
		}
	});
	this->filter.pushFilter(filter);
}
