#include "Shape.hpp"

Shape::Shape(const string color)
	:color(color)
{
}

string Shape::get_color() const
{
	return this->color;
}
