#pragma once
#include "StoreItem.hpp"
#include <vector>

class Shop {
private:
	string name;
	vector<StoreItem*> items;
public:
	Shop(const string& name = "");
	Shop(const Shop& rhs);
	Shop& operator=(const Shop& rhs);
	~Shop();

	void add_item(const StoreItem& item);
	void remove_item(const int& index);
	void change_price(const int& index, const double& price);
	void change_name(const int& index, const string& name);
	void print_info() const;
};
