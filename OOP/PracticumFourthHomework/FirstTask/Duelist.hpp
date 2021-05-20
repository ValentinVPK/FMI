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

	void duel(Duelist& opponent);

	bool save_deck(const string file_name) const;
	bool load_deck(const string file_name);
};