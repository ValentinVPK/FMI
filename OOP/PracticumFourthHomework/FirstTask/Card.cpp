
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
#include "Card.hpp"

Card::Card(const string init_name, const string init_effect, unsigned int init_rarity)
	:name(init_name), effect(init_effect), rarity(init_rarity)
{
	
}

Card::Card(const Card& rhs)
{
	this->name = rhs.name;
	this->effect = rhs.effect;
	this->rarity = rhs.rarity;
}

Card& Card::operator=(const Card& rhs)
{
	if (this != &rhs) 
	{
		this->name = rhs.name;
		this->effect = rhs.effect;
		this->rarity = rhs.rarity;
	}

	return *this;
}

Card::~Card()
{
}

ostream& operator<<(ostream& output, const Card& rhs)
{
	rhs.print(output);

	return output;
}

istream& operator>>(istream& input, Card& rhs)
{
	rhs.load(input);

	return input;
}

bool Card::operator<(const Card& rhs) const
{
	return rarity < rhs.rarity;
}

bool Card::operator>(const Card& rhs) const
{
	return rarity > rhs.rarity;
}
