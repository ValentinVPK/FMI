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
#include "Card.hpp"


class MonsterCard : virtual public Card{
protected:
	unsigned int attack_points;
	unsigned int deffence_points;
public:
	MonsterCard(const string init_name = "", const string init_effect = "", 
		unsigned int init_rarity = 0, const unsigned int init_attack = 0,
		const unsigned int init_deffence = 0);

	//MonsterCard(const MonsterCard& rhs);
	MonsterCard& operator=(const MonsterCard& rhs);

	ostream& print(ostream& output) const override;
	istream& load(istream& input) override;

};
