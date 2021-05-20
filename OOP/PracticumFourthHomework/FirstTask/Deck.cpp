
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
#include "Deck.hpp"

Deck::Deck(const string init_name)
	:name(init_name)
{
	
}

Deck::Deck(const Deck& rhs)
{
	this->name = rhs.name;
	this->cards = rhs.cards;
}

Deck& Deck::operator=(const Deck& rhs)
{
	if (this != &rhs) 
	{
		this->name = rhs.name;
		for (auto card : cards)
		{
			delete card;
		}

		this->cards = rhs.cards;
	}

	return *this;
}

void Deck::set_deck_name(const string new_name)
{
	this->name = new_name;
}

int Deck::monsters_count() const
{
	int count = 0;
	for (auto card : cards) 
	{
		if (typeid(*card) == typeid(MonsterCard)) 
		{
			count++;
		}
	}

	return count;
}

int Deck::magics_count() const
{
	int count = 0;
	for (auto card : cards)
	{
		if (typeid(*card) == typeid(MagicCard))
		{
			count++;
		}
	}

	return count;
}

int Deck::pendulums_count() const
{
	int count = 0;
	for (auto card : cards)
	{
		if (typeid(*card) == typeid(PendulumCard))
		{
			count++;
		}
	}

	return count;
}

int Deck::all_cards_count() const
{
	return this->cards.size();
}

void Deck::add_card(Card* new_card)
{
	if (typeid(*new_card) == typeid(MonsterCard)) 
	{
		MonsterCard* new_monster = dynamic_cast<MonsterCard*>(new_card);
		Card* monster_to_add = new MonsterCard(*new_monster);
		this->cards.push_back(monster_to_add);
	}

	if (typeid(*new_card) == typeid(MagicCard))
	{
		MagicCard* new_magic = dynamic_cast<MagicCard*>(new_card);
		Card* magic_to_add = new MagicCard(*new_magic);
		this->cards.push_back(magic_to_add);
	}
	
	if (typeid(*new_card) == typeid(PendulumCard))
	{
		PendulumCard* new_pendulum = dynamic_cast<PendulumCard*>(new_card);
		Card* pendulum_to_add = new PendulumCard(*new_pendulum);
		this->cards.push_back(pendulum_to_add);
	}
}

void Deck::change_card(const int index, const Card* new_card)
{
	if (typeid(*cards[index]) != typeid(*new_card)) 
	{
		cout << "Invalid operation!" << "\n";
		return;
	}

	*cards[index] = *new_card;
}

void Deck::clear_deck()
{
	for (auto card : cards)
	{
		delete card;
	}
	this->cards.clear();
}

void Deck::shuffle()
{
	unsigned seed = std::chrono::system_clock::now()
		.time_since_epoch()
		.count();
	std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));

	// Tozi shuffle go vidqh ot cplusplus.com
}

bool Deck::operator<(const Deck& rhs)
{
	if (this->cards.size() != rhs.cards.size()) 
	{
		cout << "Can't compare decks with diferent sizes!" << endl;
		return false;
	}
	unsigned int deck_points = 0, rhs_points = 0;

	for (int i = 0; i < all_cards_count(); i++)
	{
		if (*this->cards[i] < *rhs.cards[i]) 
		{
			rhs_points++;
		}
		else if (*this->cards[i] > *rhs.cards[i]) 
		{
			deck_points++;
		}
	}

	if (deck_points < rhs_points) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool Deck::operator>(const Deck& rhs)
{
	if (this->cards.size() != rhs.cards.size())
	{
		cout << "Can't compare decks with diferent sizes!" << endl;
		return false;
	}
	unsigned int deck_points = 0, rhs_points = 0;

	for (int i = 0; i < all_cards_count(); i++)
	{
		if (*this->cards[i] < *rhs.cards[i])
		{
			rhs_points++;
		}
		else if (*this->cards[i] > *rhs.cards[i])
		{
			deck_points++;
		}
	}

	if (deck_points > rhs_points)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Deck::~Deck()
{
	for (auto card : cards) 
	{
		delete card;
	}
}

ostream& operator<<(ostream& output, const Deck& rhs)
{
	output << rhs.name << "|" << rhs.all_cards_count() << "|" << rhs.monsters_count() << "|" << rhs.magics_count() << "|" << rhs.pendulums_count() << "\n";

	for (auto card : rhs.cards)
	{
		if (typeid(*card) == typeid(MonsterCard)) 
		{
			output << *card;
		}
	}

	for (auto card : rhs.cards)
	{
		if (typeid(*card) == typeid(MagicCard))
		{
			output << *card;
		}
	}

	for (auto card : rhs.cards)
	{
		if (typeid(*card) == typeid(PendulumCard))
		{
			output << *card;
		}
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

	input >> trash >> trash >> trash >> monster_count >> trash >> magic_count >> trash >> pendulum_count;
	input.get();

	for (int i = 0; i < monster_count; i++)
	{
		MonsterCard curr_monster;
		input >> curr_monster;
		rhs.add_card(&curr_monster);
	}
	
	for (int i = 0; i < magic_count; i++)
	{
		MagicCard curr_magic;
		input >> curr_magic;
		rhs.add_card(&curr_magic);
	}

	for (int i = 0; i < pendulum_count; i++)
	{
		PendulumCard curr_pendulum;
		input >> curr_pendulum;
		rhs.add_card(&curr_pendulum);
	}

	return input;
}
