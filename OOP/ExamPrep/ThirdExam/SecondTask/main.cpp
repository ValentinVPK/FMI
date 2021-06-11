#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif
#include <iostream>
#include "RepairShop.hpp"
#include "Car.hpp"
#include "Bus.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    RepairShop* shop = shop->getInstance();

    Car defaultCar;
    Bus defaultBus;
    shop->add(&defaultCar);
    shop->add(&defaultBus);

    cout << shop->hasCapacity();

    delete shop;
}

