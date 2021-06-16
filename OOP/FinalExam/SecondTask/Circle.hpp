#pragma once
#include "Shape.hpp"


class Circle : public Shape {
private:
	double radius;
public:
	Circle(const string color = "", const double radius = 0);

	double get_radius() const;

	Shape* clone() const;

	double calculate_lice() const;
};
