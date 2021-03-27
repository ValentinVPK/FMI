#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif
#include <iostream>
#include "Error.hpp"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
   
    Error err1 = Error::newNone();
    Error err2 = Error::newFailedAssertion("Fail");

    err1 = err2;
    cout << err1.getMessage();
    cout << (int)err1.getType();


}

