#include "QuadraticEquation.h"
#include <iostream>
using namespace std;


QuadraticEquation::QuadraticEquation(const ComplexNumber a, const ComplexNumber b, const ComplexNumber c) {
	setA(a);
	setB(b);
	setC(c);
}
	
ComplexNumber QuadraticEquation::getA() const{
	return this->a;
}
void QuadraticEquation::setA(ComplexNumber a) {
	this->a = a;
}

ComplexNumber QuadraticEquation::getB() const {
	return this->b;
}
void QuadraticEquation::setB(ComplexNumber b) {
	this->b = b;
}

ComplexNumber QuadraticEquation::getC() const {
	return this->c;
}
void QuadraticEquation::setC(ComplexNumber c) {
	this->c = c;
}

void QuadraticEquation::printEquation() const {
	cout << "(";
	this->a.printNumber();
	cout << ")*x^2 + (";
	this->b.printNumber();
	cout << ")*x + ";
	this->c.printNumber();
	cout << endl;
}


