#pragma once
class ComplexNumber
{
private:
	double a;
	double b;
public:
	ComplexNumber(double a, double b);

	double getA() const;
	void setA(double a);
	
	double getB() const;
	void setB(double b);

	void printNumber() const;
};

