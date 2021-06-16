#pragma once

#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include <vector>


class Shapes {
private:
	vector<Shape*> shapes;
public:
	Shapes() = default;
	Shapes(const Shapes& rhs);
	Shapes& operator=(const Shapes& rhs);
	~Shapes();

	void add(const Shape* shape);

	double rectangles_sum() const;
	double circles_sum() const;

	Shape& get_shape(const size_t index) const;
};
