#include "Shapes.hpp"

Shapes::Shapes(const Shapes& rhs)
{
	for (auto shape : rhs.shapes)
	{
		this->shapes.push_back(shape->clone());
	}
}

Shapes& Shapes::operator=(const Shapes& rhs)
{
	if (this != &rhs) {
		for (auto shape : this->shapes)
		{
			delete shape;
		}
		this->shapes.clear();

		for (auto shape : rhs.shapes)
		{
			this->shapes.push_back(shape->clone());
		}
	}

	return *this;
}

Shapes::~Shapes()
{
	for (auto shape : this->shapes)
	{
		delete shape;
	}
}

void Shapes::add(const Shape* shape)
{
	this->shapes.push_back(shape->clone());
}

double Shapes::rectangles_sum() const
{
	double result = 0;
	for (auto shape : this->shapes) 
	{
		Rectangle* rectanglePtr = dynamic_cast<Rectangle*>(shape);
		if (rectanglePtr) {
			result += rectanglePtr->calculate_lice();
		}
	}

	return result;
}

double Shapes::circles_sum() const
{
	double result = 0;
	for (auto shape : this->shapes)
	{
		Circle* circlePtr = dynamic_cast<Circle*>(shape);
		if (circlePtr) {
			result += circlePtr->calculate_lice();
		}
	}

	return result;
}

Shape& Shapes::get_shape(const size_t index) const
{
	return *shapes[index];
}
