#include "Shop.hpp"

Shop::Shop(const string& name)
	:name(name)
{

}

Shop::Shop(const Shop& rhs)
{
	this->name = rhs.name;
	for(auto item : rhs.items)
	{
		this->items.push_back(item->clone());
	}
}

Shop& Shop::operator=(const Shop& rhs)
{
	if (this != &rhs) 
	{
		this->name = rhs.name;
		for (auto item : this->items) 
		{
			delete item;
		}
		this->items.clear();

		for (auto item : rhs.items)
		{
			this->items.push_back(item->clone());
		}
	}

	return *this;
}

Shop::~Shop()
{
	for (auto item : items) 
	{
		delete item;
	}
}

void Shop::add_item(const StoreItem& item)
{
	this->items.push_back(item.clone());
}

void Shop::remove_item(const int& index)
{
	delete this->items[index];
	this->items.erase(this->items.begin() + index);
}

void Shop::change_price(const int& index, const double& price)
{
	this->items[index]->set_price(price);
}

void Shop::change_name(const int& index, const string& name)
{
	this->items[index]->set_name(name);
}

void Shop::print_info() const
{
	for (auto item : items)
	{
		item->print();
	}
}
