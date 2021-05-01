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
#include "PendulumCard.hpp"

PendulumCard::PendulumCard(const string init_name, const string init_effect, const unsigned int init_attack, const unsigned int init_deffence, const double init_scale,
	const CardType init_type)
	:Card(init_name, init_effect),
	MonsterCard(init_name, init_effect, init_attack, init_deffence),
	MagicCard(init_name, init_effect, init_type),
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

ostream& operator<<(ostream& output, const PendulumCard& rhs)
{
	output << rhs.name << "|" << rhs.effect << "|" << rhs.attack_points << "|" << rhs.deffence_points << "|" << rhs.scale << "|" << rhs.get_type_as_string() << "\n";

	return output;
}

istream& operator>>(istream& input, PendulumCard& rhs)
{
	char trash;
	char new_name[50];
	char new_effect[256];
	string new_type;

	input.get(new_name, 50, '|');

	input >> trash;
	input.get(new_effect, 256, '|');

	rhs.name = new_name;
	rhs.effect = new_effect;
	input >> trash >> rhs.attack_points >> trash >> rhs.deffence_points >> trash >> rhs.scale >> trash >> new_type;
	input.get();

	rhs.set_type(new_type);

	return input;
}
