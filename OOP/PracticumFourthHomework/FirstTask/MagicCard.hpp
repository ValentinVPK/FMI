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

enum class CardType {
	TRAP,
	BUFF,
	SPELL
};

class MagicCard : virtual public Card {
protected:
	CardType type;
	string get_type_as_string() const;
	void set_type(const string type_str);
public:
	MagicCard(const string init_name = "", const string init_effect = "", unsigned int init_rarity = 0, const CardType init_type = CardType::SPELL);

	//MagicCard(const MagicCard& rhs);
	MagicCard& operator=(const MagicCard& rhs);


	ostream& print(ostream& output) const override;
	istream& load(istream& input) override;

};
