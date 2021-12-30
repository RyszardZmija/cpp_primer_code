#include "Circle.h"

const double Circle::PI = 3.141592;

double Circle::area() const {
	return PI * dim1 * dim1;
}

double Circle::perimeter() const {
	return 2 * PI * dim1;
}