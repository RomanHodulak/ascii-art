#ifndef ASCII_ART_CONTROL_H
#define ASCII_ART_CONTROL_H

#include <ostream>
#include "Rectangle.h"

class Control {
protected:

	/** Position and size rectangle. */
	Rectangle rect;

public:

	/**
	 * Constructs control with position and size from given rectangle.
	 *
	 * @param rect Rectangle to get the dimensions from.
	 */
	explicit Control(const Rectangle & rect);

	/**
	 * Releases dynamically allocated resources, if any.
	 */
	virtual ~Control();

	/**
	 * Copies the control.
	 *
	 * @return Deep copy of this instance.
	 */
	virtual Control * clone() const = 0;

	/**
	 * Prints out the control's string representation into the given output stream.
	 *
	 * @param out Output stream to write to.
	 * @return Reference to given output stream.
	 */
	virtual std::ostream & print(std::ostream & out) = 0;

	/**
	 * Gets position and size rectangle.
	 *
	 * @return Rectangle.
	 */
	const Rectangle & getRect() const;

	friend std::ostream & operator<<(std::ostream & out, Control & control);
};

#endif //ASCII_ART_CONTROL_H
