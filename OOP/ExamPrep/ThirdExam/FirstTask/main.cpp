
#include <iostream>
#include <vector>
#include "ProtectedValue.hpp"
using namespace std;

int main()
{
    ProtectedValue<double> pr(3.14, 253);
    cout << pr.getValue(254);
    
}

