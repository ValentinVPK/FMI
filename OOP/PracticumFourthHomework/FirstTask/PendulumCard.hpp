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
#pragma once
#include "MonsterCard.hpp"
#include "MagicCard.hpp"

class PendulumCard : public MonsterCard, public MagicCard {
private:
	double scale;
public:
	PendulumCard(const string init_name = "", const string init_effect = "", unsigned int init_rarity = 0, const unsigned int init_attack = 0, const unsigned int init_deffence = 0, const double init_scale = 0, const CardType init_type = CardType::SPELL);

	PendulumCard& operator=(const PendulumCard& rhs);

	Card* clone() const override;

	ostream& print(ostream& output) const override;
	istream& load(istream& input) override;
};
