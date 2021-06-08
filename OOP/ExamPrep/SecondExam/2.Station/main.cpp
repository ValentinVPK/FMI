

#include <iostream>
#include "MeteoStation.hpp"
#include "NewspaperObserver.hpp"

int main()
{
    MeteoStation station("Sofia", 25);
    NewspaperObserver obsv1("Ivan", "Pleven", 20);
    NewspaperObserver obsv2("Dragan", "Lovech", 15);

    station.registeer(&obsv1);
    station.registeer(&obsv2);

    station.setTemperature(30);

}

