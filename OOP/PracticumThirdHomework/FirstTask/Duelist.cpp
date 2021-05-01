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
#include "Duelist.hpp"

Duelist::Duelist(const string init_name)
	:name(init_name)
{
}

Deck& Duelist::get_deck() 
{
	return this->deck;
}

bool Duelist::save_deck(const string file_name)
{
	ofstream out(file_name);
	if (!out.is_open()) 
	{
		return false;
	}

	out << this->deck;

	out.close();
	return true;
}

bool Duelist::load_deck(const string file_name)
{
	ifstream in(file_name);
	if (!in.is_open()) 
	{
		return false;
	}

	Deck new_deck;
	in >> new_deck;

	this->deck = new_deck;
	in.close();
	return true;
}
