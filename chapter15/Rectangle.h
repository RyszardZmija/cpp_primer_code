#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape_2D.h"

class Rectangle : public Shape_2D {
public:
	Rectangle() = default;
	Rectangle(double width, double height) :
		Shape_2D(width, height) {}

	double area() const override;
	double perimeter() const override;

private:

};
#endif