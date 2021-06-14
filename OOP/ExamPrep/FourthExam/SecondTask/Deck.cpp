#include "Deck.hpp"

Deck::Deck(const Deck& rhs)
{
	for (auto card : rhs.deck) {
		this->deck.push_back(card->clone());
	}
}

Deck& Deck::operator=(const Deck& rhs)
{
	if (this != &rhs) {
		for (auto card : this->deck) {
			delete card;
		}

		this->deck.clear();

		for (auto card : rhs.deck) {
			this->deck.push_back(card->clone());
		}
	}

	return *this;
}

Deck::~Deck()
{
	for (auto card : this->deck) {
		delete card;
	}
}

void Deck::add_card(const Card* card)
{
	this->deck.push_back(card->clone());
}

void Deck::print() const
{
	for (auto card : this->deck) {
		card->print();
	}
}
