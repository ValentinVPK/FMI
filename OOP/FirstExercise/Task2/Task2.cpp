
#include <iostream>
#include "ComplexNumber.h"
using namespace std;

ComplexNumber addComplexNumbers(ComplexNumber num1, ComplexNumber num2) {
    ComplexNumber result(num1.getA() + num2.getA(), num1.getB() + num2.getB());

    return result;
}

ComplexNumber multiplyComplexNumbers(ComplexNumber num1, ComplexNumber num2) {
    ComplexNumber result(num1.getA() * num2.getA() + (-1) * num1.getB() * num2.getB(),
        num1.getA() * num2.getB() + num1.getB() * num2.getA());

    return result;
}

int main()
{
    ComplexNumber num1(1, 3);
    ComplexNumber num2(1, -2);

    num1.printNumber();
    num2.printNumber();

    ComplexNumber addedNumber = addComplexNumbers(num1, num2);
    addedNumber.printNumber();

    ComplexNumber multipliedNumber = multiplyComplexNumbers(num1, num2);
    multipliedNumber.printNumber();
}

