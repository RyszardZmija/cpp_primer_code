#include "Rectangle.h"

double Rectangle::area() const {
	return dim1 * dim2;
}

double Rectangle::perimeter() const {
	return 2 * dim1 + 2 * dim2;
}