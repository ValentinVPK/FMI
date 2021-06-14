#pragma once
#include <string>
#include <iostream>
using namespace std;

class Card {
protected:
	string name;
	size_t cardNumber;
	size_t imageNumber;
public:
	Card(const string& name = "", const size_t& cardNumber = 0, 
		const size_t& imageNumber = 0);
	virtual ~Card() = default;

	string get_name() const;
	size_t get_cardNumber() const;
	size_t get_imageNumber() const;

	void print() const;

	virtual Card* clone() const = 0;
};
