#include "Vector4D.hpp"

Vector4D::Vector4D(double a, double b, double c, double d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}

double& Vector4D::operator[](int index)
{
	// first error
	if (index == 0) 
	{
		return this->a;
	}	
	else if (index == 1) 
	{
		return this->b;
	}
	else if (index == 2) 
	{
		return this->c;
	}
	else  
	{
		return this->d;
	}
}

Vector4D& Vector4D::operator+=(const Vector4D& rhs)
{
	this->a += rhs.a;
	this->b += rhs.b;
	this->c += rhs.c;
	this->d += rhs.d;
	return *this;
}

Vector4D& Vector4D::operator-=(const Vector4D& rhs)
{
	this->a -= rhs.a;
	this->b -= rhs.b;
	this->c -= rhs.c;
	this->d -= rhs.d;
	return *this;
}

Vector4D& Vector4D::operator*=(const Vector4D& rhs)
{
	this->a *= rhs.a;
	this->b *= rhs.b;
	this->c *= rhs.c;
	this->d *= rhs.d;
	return *this;
}

Vector4D& Vector4D::operator*=(double number)
{
	this->a *= number;
	this->b *= number;
	this->c *= number;
	this->d *= number;

	return *this;
}


Vector4D& Vector4D::operator/=(const Vector4D& rhs)
{
	this->a /= rhs.a;
	this->b /= rhs.b;
	this->c /= rhs.c;
	this->d /= rhs.d;
	return *this;
}

bool Vector4D::operator!() const
{
	if (this->a == 0 && this->b == 0 && this->c == 0 && this->d == 0) {
		return true;
	}

	return false;
}

Vector4D Vector4D::operator-() const
{
	return Vector4D(this->a * (-1), this->b * (-1), this->c * (-1), this->d * (-1));
}

Vector4D operator+(const Vector4D& v1, const Vector4D& v2)
{
	return Vector4D(v1.a + v2.a, v1.b + v2.b, v1.c + v2.c, v1.d + v2.d);
}

Vector4D operator-(const Vector4D& v1, const Vector4D& v2)
{
	return Vector4D(v1.a - v2.a, v1.b - v2.b, v1.c - v2.c, v1.d - v2.d);
}

Vector4D operator*(const Vector4D& v1, const Vector4D& v2)
{
	return Vector4D(v1.a * v2.a, v1.b * v2.b, v1.c * v2.c, v1.d * v2.d);
}

Vector4D operator*(const Vector4D& v1, double number)
{
	return Vector4D(v1.a * number, v1.b * number, v1.c * number, v1.d * number);
}

Vector4D operator/(const Vector4D& v1, const Vector4D& v2)
{
	return Vector4D(v1.a / v2.a, v1.b / v2.b, v1.c / v2.c, v1.d / v2.d);
}

bool operator==(const Vector4D& lhs, const Vector4D& rhs)
{
	if (lhs.a == rhs.a && lhs.b == rhs.b && lhs.c == rhs.c && lhs.d == rhs.d)
	{
		return true;
	}
	
	return false;
}

bool operator!=(const Vector4D& lhs, const Vector4D& rhs)
{
	if (lhs.a == rhs.a && lhs.b == rhs.b && lhs.c == rhs.c && lhs.d == rhs.d)
	{
		return false;
	}
	
	return true;
}

bool operator<(const Vector4D& lhs, const Vector4D& rhs)
{
	if (lhs.a < rhs.a)
	{
		return true;
	}
	else if (lhs.a > rhs.a) {
		return false;
	}

	if (lhs.b < rhs.b)
	{
		return true;
	}
	else if (lhs.b > rhs.b) {
		return false;
	}

	if (lhs.c < rhs.c)
	{
		return true;
	}
	else if (lhs.c > rhs.c) {
		return false;
	}

	if (lhs.d < rhs.d)
	{
		return true;
	}
	else if (lhs.d > rhs.d) {
		return false;
	}

	return false; // This means lhs == rhs
}

bool operator>(const Vector4D& lhs, const Vector4D& rhs)
{
	if (lhs.a > rhs.a)
	{
		return true;
	}
	else if (lhs.a < rhs.a) {
		return false;
	}

	if (lhs.b > rhs.b)
	{
		return true;
	}
	else if (lhs.b < rhs.b) {
		return false;
	}

	if (lhs.c > rhs.c)
	{
		return true;
	}
	else if (lhs.c < rhs.c) {
		return false;
	}

	if (lhs.d > rhs.d)
	{
		return true;
	}
	else if (lhs.d < rhs.d) {
		return false;
	}

	return false; // This means lhs == rhs
}

bool operator<=(const Vector4D& lhs, const Vector4D& rhs)
{
	if (lhs.a < rhs.a)
	{
		return true;
	}
	else if (lhs.a > rhs.a) {
		return false;
	}

	if (lhs.b < rhs.b)
	{
		return true;
	}
	else if (lhs.b > rhs.b) {
		return false;
	}

	if (lhs.c < rhs.c)
	{
		return true;
	}
	else if (lhs.c > rhs.c) {
		return false;
	}

	if (lhs.d < rhs.d)
	{
		return true;
	}
	else if (lhs.d > rhs.d) {
		return false;
	}

	return true; // This means lhs == rhs
}

bool operator>=(const Vector4D& lhs, const Vector4D& rhs)
{
	if (lhs.a > rhs.a)
	{
		return true;
	}
	else if (lhs.a < rhs.a) {
		return false;
	}

	if (lhs.b > rhs.b)
	{
		return true;
	}
	else if (lhs.b < rhs.b) {
		return false;
	}

	if (lhs.c > rhs.c)
	{
		return true;
	}
	else if (lhs.c < rhs.c) {
		return false;
	}

	if (lhs.d > rhs.d)
	{
		return true;
	}
	else if (lhs.d < rhs.d) {
		return false;
	}

	return true; // This means lhs == rhs
}


