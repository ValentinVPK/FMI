#pragma once
#include "Card.hpp"
#include <vector>

class Deck {
private:
	vector<Card*> deck;
public:
	Deck() = default;
	Deck(const Deck& rhs);
	Deck& operator=(const Deck& rhs);
	~Deck();

	void add_card(const Card* card);
	void print() const;
};
