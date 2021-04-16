
#include <iostream>
#include "Vector4D.hpp"
using namespace std;

int main()
{
    Vector4D vec(1, 2, 3, 4);
    Vector4D vec2(2, 2, 2, 2);
    
    
    cout << vec[0] << " " << vec[1] << " " << vec[2] << " " << vec[3] << endl;
}

