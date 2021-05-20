
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
#include "Duelist.hpp"

Duelist::Duelist(const string init_name)
	:name(init_name)
{
}

Deck& Duelist::get_deck()
{
	return this->deck;
}

void Duelist::duel(Duelist& opponent)
{
	if (this->deck.all_cards_count() != opponent.deck.all_cards_count()) 
	{
		cout << "The duelists must have equal amount of cards in their decks!" << "\n";
		return;
	}

	this->deck.shuffle();
	opponent.deck.shuffle();

	if (this->deck > opponent.deck) 
	{
		cout << this->name << " wins the duel!" << "\n";
	}
	else if (this->deck < opponent.deck) 
	{
		cout << opponent.name << " wins the duel!" << "\n";
	}
	else 
	{
		cout << "Draw!" << "\n";
	}
}

bool Duelist::save_deck(const string file_name) const
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

	this->deck.clear_deck();
	in >> this->deck;
	in.close();
	return true;
}