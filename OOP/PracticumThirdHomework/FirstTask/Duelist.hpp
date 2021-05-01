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
#pragma once
#include "Deck.hpp"
#include <fstream>
#include <iostream>

class Duelist {
private:
	string name;
	Deck deck;
public:
	Duelist(const string init_name = "");

	Deck& get_deck();

	bool save_deck(const string file_name);
	bool load_deck(const string file_name);
};
