#pragma warning(disable : 4996)
#include <iostream>
#include "VendingMachine.hpp"

using namespace std;

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // DRINKS RESTING:

    Drink dr("Cola", 500, 0.500, 3.5);
    //cout << dr.get_name() << " " << dr.get_calories() << " " << dr.get_quantity() << " " << dr.get_price() << endl;

    Drink dr1("Pepsi", 450, 0.400, 2.3);
    Drink drC(dr);

    dr1.set_name("Cola");

    //cout << dr1.get_name() << " " << dr1.get_calories() << " " << dr1.get_quantity() << " " << dr1.get_price() << endl;

    //Drink dr2;
    //
    //cout << dr2.get_name() << " " << dr2.get_calories() << " " << dr2.get_quantity() << " " << dr2.get_price() << endl;

    // VENDING MACHINE TESTING:

    VendingMachine machine;
    machine.add_drink(dr);
    machine.add_drink(dr1);
    machine.add_drink(dr);
    //machine.buy_drink("Pepsi", 3.3);
    machine.buy_drink("Pepsi", 2.0);
    //machine.print_drinks();
    //cout << machine.get_income();

    VendingMachine copy;
    copy = machine;

    copy.buy_drink("Pepsi", 2.5);
    
    //machine.print_drinks();
    cout << machine.get_income() << endl;

    //copy.print_drinks();
    cout << copy.get_income();
}


