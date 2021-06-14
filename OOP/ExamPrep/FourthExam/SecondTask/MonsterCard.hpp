#pragma once
#include "Card.hpp"

class MonsterCard : virtual public Card {
protected:
	size_t attackPoints;
	size_t deffencePoints;
public:
	MonsterCard(const string& name = "", const size_t& cardNumber = 0,
		const size_t& imageNumber = 0, const size_t& attackPoints = 0, 
		const size_t& deffencePoints = 0);

	size_t get_attackPoints() const;
	size_t get_deffencePoints() const;

	Card* clone() const override;
	void print() const;
};
