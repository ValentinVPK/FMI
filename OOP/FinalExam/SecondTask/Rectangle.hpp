#pragma once
#include "Shape.hpp"

class Rectangle : public Shape {
private:
	double length;
	double width;
public:
	Rectangle(const string color = "", const double length = 0, const double width = 0);

	double get_length() const;
	double get_width() const;

	Shape* clone() const;

	double calculate_lice() const;
};
