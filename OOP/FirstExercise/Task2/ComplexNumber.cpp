#include "ComplexNumber.h"
#include <iostream>
using namespace std;

ComplexNumber::ComplexNumber(double a, double b) {
	setA(a);
	setB(b);
}

double ComplexNumber::getA() const{
	return this->a;
}
void ComplexNumber::setA(double a) {
	this->a = a;
}

double ComplexNumber::getB() const {
	return this->b;
}
void ComplexNumber::setB(double b) {
	this->b = b;
}

void ComplexNumber::printNumber() const{
	if (b < 0) {
		cout << this->a << " + (" << this->b << ")*i" << endl;
	}
	else {
		cout << this->a << " + " << this->b << "*i" << endl;
	}
}
