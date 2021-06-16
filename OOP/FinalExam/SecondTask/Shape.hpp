#pragma once
#include <string>
using namespace std;

class Shape {
protected:
	string color;
public:
	Shape(const string color = "");
	virtual ~Shape() = default;
	
	string get_color() const;

	virtual Shape* clone() const = 0;

	virtual double calculate_lice()const = 0;
};

