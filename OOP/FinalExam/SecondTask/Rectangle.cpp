#include "Rectangle.hpp"

Rectangle::Rectangle(const string color, const double length, const double width)
	:Shape(color), length(length), width(width)
{
}

double Rectangle::get_length() const
{
	return this->length;
}

double Rectangle::get_width() const
{
	return this->width;
}

Shape* Rectangle::clone() const
{
	return new Rectangle(*this);
}

double Rectangle::calculate_lice() const
{
	return this->length * this->width;
}
