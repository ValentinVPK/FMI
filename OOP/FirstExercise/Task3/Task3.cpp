
#include <iostream>
#include "WaterDispenser.h"
using namespace std;

int main()
{
    WaterDispenser waterDis(10, 25);

    waterDis.fillDispenser(16);
    cout << waterDis.getCurrLiters() << endl;

    waterDis.fillCup(500);
    cout << waterDis.getCurrLiters() << endl;
}

