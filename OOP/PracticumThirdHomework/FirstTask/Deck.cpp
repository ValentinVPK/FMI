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
#include "Deck.hpp"

Deck::Deck(const string init_name)
	:name(init_name)
{
	
}

Deck& Deck::operator=(const Deck& rhs)
{
	if (this != &rhs) 
	{
		this->name = rhs.name;
		this->monster_cards = rhs.monster_cards;
		this->magic_cards = rhs.magic_cards;
		this->pendulum_cards = rhs.pendulum_cards;
	}

	return *this;
}

void Deck::set_deck_name(const string new_name)
{
	this->name = new_name;
}

int Deck::monsters_count() const
{
	return this->monster_cards.size();
}

int Deck::magics_count() const
{
	return this->magic_cards.size();
}

int Deck::pendulums_count() const
{
	return this->pendulum_cards.size();
}

void Deck::add_monster(const MonsterCard& monster_card)
{
	this->monster_cards.push_back(monster_card);
}

void Deck::add_magic(const MagicCard& magic_card)
{
	this->magic_cards.push_back(magic_card);
}

void Deck::add_pendulum(const PendulumCard& pendulum_card)
{
	this->pendulum_cards.push_back(pendulum_card);
}

void Deck::change_monster(const int index, const MonsterCard& monster_card)
{
	if (index < 0 || index >= this->monster_cards.size()) 
	{
		cout << "Invalid index!" << endl;
	}
	else 
	{
		this->monster_cards[index] = monster_card;
	}
}

void Deck::change_magic(const int index, const MagicCard& magic_card)
{
	if (index < 0 || index >= this->magic_cards.size())
	{
		cout << "Invalid index!" << endl;
	}
	else
	{
		this->magic_cards[index] = magic_card;
	}
}

void Deck::change_pendulum(const int index, const PendulumCard& pendulum_card)
{
	if (index < 0 || index >= this->pendulum_cards.size())
	{
		cout << "Invalid index!" << endl;
	}
	else
	{
		this->pendulum_cards[index] = pendulum_card;
	}
}

void Deck::clear_deck()
{
	this->monster_cards.clear();
	this->magic_cards.clear();
	this->pendulum_cards.clear();
}

ostream& operator<<(ostream& output, const Deck& rhs)
{
	output << rhs.name << "|" << rhs.monsters_count() << "|" << rhs.magics_count() << "|" << rhs.pendulums_count() << "\n";

	for (int i = 0; i < rhs.monsters_count(); i++)
	{
		output << rhs.monster_cards[i];
	}

	for (int i = 0; i < rhs.magics_count(); i++)
	{
		output << rhs.magic_cards[i];
	}

	for (int i = 0; i < rhs.pendulums_count(); i++)
	{
		output << rhs.pendulum_cards[i];
	}

	return output;
}

istream& operator>>(istream& input, Deck& rhs)
{
	char trash;
	char new_name[50];
	int monster_count, magic_count, pendulum_count;

	input.get(new_name, 50, '|');
	rhs.name = new_name;

	input >> trash >> monster_count >> trash >> magic_count >> trash >> pendulum_count;
	input.get();

	for (int i = 0; i < monster_count; i++)
	{
		MonsterCard curr_card;
		input >> curr_card;
		rhs.add_monster(curr_card);
	}

	for (int i = 0; i < magic_count; i++)
	{
		MagicCard curr_card;
		input >> curr_card;
		rhs.add_magic(curr_card);
	}

	for (int i = 0; i < pendulum_count; i++)
	{
		PendulumCard curr_card;
		input >> curr_card;
		rhs.add_pendulum(curr_card);
	}

	return input;
}
