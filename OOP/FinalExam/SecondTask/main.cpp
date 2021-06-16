// FN: 62539, Group : 2
//IDE: Visual Studio 2019
//Compiler : VC
#include <iostream>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Shapes.hpp"

int main()
{
    Shapes test;

    Circle circle1("blue", 3);
    Circle circle2("red", 5);

    Rectangle rectangle1("black", 10, 7);
    Rectangle rectangle2("orange", 8, 6);

    test.add(&circle1);
    test.add(&circle2);

    test.add(&rectangle1);
    test.add(&rectangle2);

    cout << test.circles_sum() << endl;
    cout << test.rectangles_sum() << endl;

    cout << test.get_shape(2).calculate_lice();
}


