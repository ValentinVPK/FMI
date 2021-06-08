#include "Shoes.hpp"

Shoes::Shoes(const string& name, const double& price, const string& color, const string& size)
    :StoreItem(ItemType::Shoes, name, price), color(color), size(size)
{
}

StoreItem* Shoes::clone() const
{
    return new Shoes(*this);
}

void Shoes::print() const
{
    cout << "Item Type: Shoes" << " Name: " << this->name << " Price: " << this->price << " Color: " << this->color << " Size: " << this->size << "\n";
}

string Shoes::get_color() const
{
    return this->color;
}

string Shoes::get_size() const
{
    return this->size;
}

void Shoes::set_color(const string& color)
{
    this->color = color;
}

void Shoes::set_size(const string& size)
{
    this->size = size;
}

bool Shoes::operator>(const Shoes& rhs)
{
    if (this->size == "females" && rhs.size == "children") 
    {
        return true;
    }

    if (this->size == "men" && rhs.size != "men") 
    {
        return true;
    }

    return false;
}
