/**
* Solution to homework assignment 4
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Valentin Krumov
* @idnumber 62539
* @task 1
* @compiler VC
*/

#pragma once
#include <string>
#include <iostream>
#include <typeinfo>
using namespace std;

class Card {
protected:
	string name;
	string effect;
	unsigned int rarity;
public:
	Card(const string init_name = "", const string init_effect = "", unsigned int init_rarity = 0);

	Card(const Card& rhs);
	Card& operator=(const Card& rhs);

	virtual ostream& print(ostream& output) const = 0;
	virtual istream& load(istream& input) = 0;
	virtual Card* clone() const = 0;

	virtual ~Card();

	friend ostream& operator<<(ostream& output, const Card& rhs);
	friend istream& operator>>(istream& input, Card& rhs);

	bool operator<(const Card& rhs) const;
	bool operator>(const Card& rhs) const;
};
