#pragma once
#include "drink.hpp"

class VendingMachine {
public:
    VendingMachine();
    VendingMachine(const VendingMachine& from);
    VendingMachine& operator=(const VendingMachine& from);
    ~VendingMachine();

    bool add_drink(const Drink& to_add);
    int buy_drink(const char* drink_name, const double money);

    double get_income() const;

    int get_number_of_elements() const;
private:
    Drink* drinks;
    unsigned int number_of_elements;
    double income;
    int search_for_drink(const char* drink_name) const;
};
