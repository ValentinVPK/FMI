#include "TShirt.hpp"

TShirt::TShirt(const string& name, const double& price, const string& color, const string& size)
	:StoreItem(ItemType::Tshirt, name, price), color(color), size(size)
{
}

StoreItem* TShirt::clone() const
{
	return new TShirt(*this);
}

void TShirt::print() const
{
	cout << "Item Type: TShirt" << " Name: " << this->name << " Price: " << this->price << " Color: " << this->color << " Size: " << this->size << "\n";
}

string TShirt::get_color() const
{
	return this->color;
}

string TShirt::get_size() const
{
	return this->size;
}

void TShirt::set_color(const string& color)
{
	this->color = color;
}

void TShirt::set_size(const string& size)
{
	this->size = size;
}

bool TShirt::operator==(const TShirt& rhs)
{
	return this->color == rhs.color && this->size == rhs.size;
}
