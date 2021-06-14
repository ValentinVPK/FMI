#pragma once
#include "Card.hpp"

class MagicCard : virtual public Card {
protected:
	string effect;
public:
	MagicCard(const string& name = "", const size_t& cardNumber = 0,
		const size_t& imageNumber = 0, const string& effect = "");

	string get_effect() const;

	Card* clone() const override;
	void print() const;
};
