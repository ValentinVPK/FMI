/**
* Solution to homework assignment 1
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
	MagicCard(const string init_name = "", const string init_effect = "", const CardType init_type = CardType::SPELL);

	MagicCard& operator=(const MagicCard& rhs);

	friend ostream& operator<<(ostream& output, const MagicCard& rhs);
	friend istream& operator>>(istream& input, MagicCard& rhs);
};
