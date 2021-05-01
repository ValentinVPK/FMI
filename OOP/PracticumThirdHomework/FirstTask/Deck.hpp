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
#include "PendulumCard.hpp"
#include "MagicCard.hpp"
#include "MonsterCard.hpp"
#include <vector>
#include <iostream>

class Deck {
private:
	string name;
	vector<MonsterCard> monster_cards;
	vector<MagicCard> magic_cards;
	vector<PendulumCard> pendulum_cards;
public:
	Deck(const string init_name = "");
	Deck& operator=(const Deck& rhs);

	void set_deck_name(const string new_name);

	int monsters_count() const;
	int magics_count() const;
	int pendulums_count() const;

	void add_monster(const MonsterCard& monster_card);
	void add_magic(const MagicCard& magic_card);
	void add_pendulum(const PendulumCard& pendulum_card);

	void change_monster(const int index,const MonsterCard& monster_card);
	void change_magic(const int index, const MagicCard& magic_card);
	void change_pendulum(const int index, const PendulumCard& pendulum_card);

	void clear_deck();

	friend ostream& operator<<(ostream& output, const Deck& rhs);
	friend istream& operator>>(istream& input, Deck& rhs);
};
