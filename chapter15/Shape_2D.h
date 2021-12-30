#ifndef SHAPE_2D_H
#define SHAPE_2D_H

class Shape_2D {
public:
	Shape_2D() = default;
	Shape_2D(double dim1, double dim2, bool drawable = true) :
		dim1(dim1), dim2(dim2), drawable(drawable) {}

	bool is_drawable() const { return drawable; }

	virtual double area() const = 0;
	virtual double perimeter() const = 0;

protected:
	double dim1 = 0.0;
	double dim2 = 0.0;
private:
	bool drawable = true;
};
#endif