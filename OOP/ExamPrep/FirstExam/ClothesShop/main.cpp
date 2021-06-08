
#include <iostream>
#include "Shop.hpp"
#include "Shoes.hpp"
#include "StoreItem.hpp"
#include "TShirt.hpp"

int main()
{
    TShirt shirt1("Gucci", 200, "blue", "M");
    TShirt shirt2("Nike", 20, "black", "S");

    Shoes shoes1("Puma", 300, "brown", "children");
    Shoes shoes2("Balenciaga", 1000, "grey", "men");

    Shop shop("Mall");
    shop.add_item(shirt1);
    shop.add_item(shirt2);
    shop.add_item(shoes1);
    shop.add_item(shoes2);

    shop.remove_item(3);
    shop.change_name(0, "Supreme");
    shop.change_price(1, 50);

    shop.print_info();
}


