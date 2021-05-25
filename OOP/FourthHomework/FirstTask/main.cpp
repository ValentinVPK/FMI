
#include "Message.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include <iostream>
using namespace std;

int main()
{
    Message m1(1), m2(2), m3(2);

    PeriodicSampler ps("ada",3);

    ps.signal(1);
    ps.signal(2);
    ps.signal(3);
    ps.signal(4);
    ps.signal(5);
    ps.signal(6);
    ps.signal(7);
    ps.signal(8);
    ps.signal(9);

    cout << ps.read();
}
