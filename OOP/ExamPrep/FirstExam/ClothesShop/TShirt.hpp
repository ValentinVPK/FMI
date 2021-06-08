#pragma once
#include "StoreItem.hpp"


class TShirt : public StoreItem {
private:
	string color;
	string size;
public:
	TShirt(const string& name = "", const double& price = 0,const string& color = "", 
		const string& size = "");

	StoreItem* clone() const;
	void print() const;

	string get_color() const;
	string get_size() const;

	void set_color(const string& color);
	void set_size(const string& size);

	bool operator==(const TShirt& rhs);
};
