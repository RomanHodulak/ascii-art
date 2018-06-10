#ifndef ASCII_ART_RECTANGLE_H
#define ASCII_ART_RECTANGLE_H

#include <cstddef>

/**
 * Immutable rectangle object, with position and size.
 */
class Rectangle {
public:
	int x;
	int y;
	int width;
	int height;

	Rectangle();

	Rectangle(int x, int y, int w, int h);
};

#endif //ASCII_ART_RECTANGLE_H
