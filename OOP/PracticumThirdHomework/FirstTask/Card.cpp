/**
* Solution to homework assignment 1
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

Card::Card(const string init_name, const string init_effect)
	:name(init_name), effect(init_effect)
{
	
}

Card& Card::operator=(const Card& rhs)
{
	if (this != &rhs) 
	{
		this->name = rhs.name;
		this->effect = rhs.effect;
	}

	return *this;
}
