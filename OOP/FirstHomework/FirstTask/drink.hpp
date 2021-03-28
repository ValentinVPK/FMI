#pragma once
#include <cstring>
class Drink {
public:
    Drink();
    Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price);
    Drink(const Drink& other_drink);
    Drink& operator=(const Drink& other_drink);
    ~Drink();

    const char* get_name() const;
    int get_calories() const;
    double get_quantity() const;
    double get_price() const;

    void set_name(const char* new_name);

private:
    char* name;
    int calories;
    double quantity;
    double price;

};
