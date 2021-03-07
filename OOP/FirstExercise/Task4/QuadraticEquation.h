#pragma once
#include "ComplexNumber.h"
class QuadraticEquation
{
private:
	ComplexNumber a;
	ComplexNumber b;
	ComplexNumber c;
public:
	QuadraticEquation(const ComplexNumber a, const ComplexNumber b, const ComplexNumber c);

	ComplexNumber getA() const;
	void setA(ComplexNumber a);

	ComplexNumber getB() const;
	void setB(ComplexNumber b);

	ComplexNumber getC() const;
	void setC(ComplexNumber c);

	void printEquation() const;
};

