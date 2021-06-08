#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif
#include <iostream>
#include "ArrayVector.hpp"
using namespace std;

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    ArrayVector<int> vec;
    vec.add(0);
    vec.add(1);
    vec.add(2);
    vec.add(3);
    vec.add(4);
    vec.add(5);

    vec.remove(3);
    vec.add(3);
    vec.print();
}


