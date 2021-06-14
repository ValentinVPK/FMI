#pragma once
#include "MagicCard.hpp"
#include"MonsterCard.hpp"
#include "Card.hpp"

class SpecialCard : public MonsterCard, public MagicCard {
private:
	size_t level;
public:
	SpecialCard(const string& name = "", const size_t& cardNumber = 0,
		const size_t& imageNumber = 0, const size_t& attackPoints = 0,
		const size_t& deffencePoints = 0, const string& effect = "", 
		const size_t& level = 0);

	size_t get_level() const;

	Card* clone() const override;
	void print() const;

};
