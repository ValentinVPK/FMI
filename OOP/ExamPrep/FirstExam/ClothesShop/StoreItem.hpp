#pragma once
#include <string>
#include <iostream>
using namespace std;

enum class ItemType {
	Tshirt,
	Shoes,
	Unknown
};

class StoreItem {
protected:
	ItemType type;
	string name;
	double price;
public:
	StoreItem(const ItemType type = ItemType::Unknown, const string& name = "", const double& price = 0);

	ItemType get_type() const;
	string get_name() const;
	double get_price() const;

	void set_type(const ItemType& type);
	void set_name(const string& name);
	void set_price(const double& price);

	virtual StoreItem* clone() const = 0;
	virtual void print() const = 0;

	virtual ~StoreItem() = default;
};
