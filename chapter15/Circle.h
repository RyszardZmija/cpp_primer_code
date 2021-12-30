#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape_2D.h"

class Circle : public Shape_2D {
public:
	Circle() = default;
	explicit Circle(double radius) :
		Shape_2D(radius, radius) {}

	double area() const override;
	double perimeter() const override;

private:
	static const double PI;
};
#endif