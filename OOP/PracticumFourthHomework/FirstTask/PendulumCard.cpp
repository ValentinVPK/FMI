
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
#include "PendulumCard.hpp"

PendulumCard::PendulumCard(const string init_name, const string init_effect, unsigned int init_rarity, const unsigned int init_attack, const unsigned int init_deffence, const double init_scale, const CardType init_type)
	:Card(init_name, init_effect, init_rarity),
	MonsterCard(init_name, init_effect, init_rarity, init_attack, init_deffence),
	MagicCard(init_name, init_effect, init_rarity, init_type),
	scale(init_scale)
{
	
}

PendulumCard& PendulumCard::operator=(const PendulumCard& rhs)
{
	if (this != &rhs) 
	{
		Card::operator=(rhs);
		MonsterCard::operator=(rhs);
		MagicCard::operator=(rhs);
		this->scale = rhs.scale;
	}

	return *this;
}

Card* PendulumCard::clone() const
{
	return new PendulumCard(*this);
}

ostream& PendulumCard::print(ostream& output) const
{
	output << name << "|" << effect << "|" << rarity << "|" << attack_points << "|" << deffence_points << "|" << scale << "|" << get_type_as_string() << "\n";

	return output;
}

istream& PendulumCard::load(istream& input)
{
	char trash;
	char new_name[50];
	char new_effect[256];
	string new_type;

	input.get(new_name, 50, '|');

	input >> trash;
	input.get(new_effect, 256, '|');

	name = new_name;
	effect = new_effect;
	input >> trash >> rarity >> trash >> attack_points >> trash >> deffence_points >> trash >> scale >> trash >> new_type;
	input.get();

	set_type(new_type);

	return input;
}

