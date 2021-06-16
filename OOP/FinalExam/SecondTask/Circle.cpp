#include "Circle.hpp"

Circle::Circle(const string color, const double radius)
	:Shape(color), radius(radius)
{
}

double Circle::get_radius() const
{
	return this->radius;
}

Shape* Circle::clone() const
{
	return new Circle(*this);
}

double Circle::calculate_lice() const
{
	return 2 * 3.14 * radius;
}
