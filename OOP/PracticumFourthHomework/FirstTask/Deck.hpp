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
#include "PendulumCard.hpp"
#include "MagicCard.hpp"
#include "MonsterCard.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

class Deck {
private:
	string name;
	vector<Card*> cards;
public:
	Deck(const string init_name = "");
	Deck(const Deck& rhs);
	Deck& operator=(const Deck& rhs);
	~Deck();

	void set_deck_name(const string new_name);

	int monsters_count() const;
	int magics_count() const;
	int pendulums_count() const;
	int all_cards_count() const;

	void add_card(Card* new_card);

	void change_card(const int index,const Card* new_card);

	void clear_deck();

	void shuffle();

	bool operator<(const Deck& rhs);
	bool operator>(const Deck& rhs);

	friend ostream& operator<<(ostream& output, const Deck& rhs);
	friend istream& operator>>(istream& input, Deck& rhs);
};
