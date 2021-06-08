#include "StoreItem.hpp"

StoreItem::StoreItem(const ItemType type, const string& name, const double& price)
	:type(type), name(name), price(price)
{
}

ItemType StoreItem::get_type() const
{
	return this->type;
}

string StoreItem::get_name() const
{
	return this->name;
}

double StoreItem::get_price() const
{
	return this->price;
}

void StoreItem::set_type(const ItemType& type)
{
	this->type = type;
}

void StoreItem::set_name(const string& name)
{
	this->name = name;
}

void StoreItem::set_price(const double& price)
{
	this->price = price;
}
