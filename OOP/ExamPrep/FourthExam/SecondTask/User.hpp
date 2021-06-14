#pragma once
#include "Deck.hpp"
#include "Card.hpp"

class User {
private:
	Deck userDeck;
public:
	User() = default;

	void add_card(const Card* card);
	void print() const;
};
