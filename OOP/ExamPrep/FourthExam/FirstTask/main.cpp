#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif
#include <iostream>
#include <string>
#include <vector>
#include "IntegerOperation.hpp"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	IntegerOperation test;
	test.insert(5);
	test.insert(3);
	test.insert(7);
	IntegerOperation test2;
	test2.insert(2);
	test2.insert(14);
	test2.insert(4);
	std::cout << test + test2 << std::endl;
	std::cout << test - test2 << std::endl;
	std::cout << test * test2 << std::endl;

}



