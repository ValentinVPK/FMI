
#include <iostream>
#include "QuadraticEquation.h"
using namespace std;

int main()
{
    ComplexNumber a(1, -3);
    ComplexNumber b(-1, 5);
    ComplexNumber c(3, -6);

    QuadraticEquation eq(a, b, c);

    eq.printEquation();
}


