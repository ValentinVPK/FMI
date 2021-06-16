// FN: 62539, Group: 2 
// IDE: Visual stuido 2019
// Compiler: VC

#pragma warning(disable : 4996) // needed for strcpy error
#include <iostream>
#include "NamedObjectArray.hpp"
#include "NamedObject.hpp"

int main()
{

    NamedObjectArray<int> arrInt;

    NamedObject<int> number1(10, "Five", 5);
    NamedObject<int> number2(20, "Six", 6);

    arrInt.add(number1);
    arrInt.add(number2);

    std::cout << arrInt[0].get_name() << std::endl;
    std::cout << arrInt[1].get_name() << std::endl;
}

