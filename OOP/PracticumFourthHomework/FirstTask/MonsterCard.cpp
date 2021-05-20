
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
#include "MonsterCard.hpp"

MonsterCard::MonsterCard(const string init_name,const string init_effect, unsigned int init_rarity, const unsigned int init_attack, const unsigned int init_deffence)
	:Card(init_name, init_effect, init_rarity), attack_points(init_attack), 
	deffence_points(init_deffence)
{
}

//MonsterCard::MonsterCard(const MonsterCard& rhs)
//{
//	this->name = rhs.name;
//	this->effect = rhs.effect;
//	this->rarity = rhs.rarity;
//	this->attack_points = rhs.attack_points;
//	this->deffence_points = rhs.deffence_points;
//}

MonsterCard& MonsterCard::operator=(const MonsterCard& rhs)
{
	if (this != &rhs) {
		Card::operator=(rhs);
		this->attack_points = rhs.attack_points;
		this->deffence_points = rhs.deffence_points;
	}

	return *this;
}

ostream& MonsterCard::print(ostream& output) const
{
	output << name << "|" << effect << "|" << rarity << "|" << attack_points << "|" << deffence_points << "\n";

	return output;
}

istream& MonsterCard::load(istream& input)
{
	//Pravq cheteneto po tozi nachin s get, zashtoto ne uspqh da izmislq po-umen nachin da obrabotq whitespace-ovete...

	char trash; // tozi char izhuvrlq '|'
	char new_name[50];
	char new_effect[256];
	input.get(new_name, 50, '|');

	input >> trash;
	input.get(new_effect, 256, '|');

	name = new_name;
	effect = new_effect;
	input >> trash >> rarity >> trash >> attack_points >> trash >> deffence_points;
	input.get(); // tozi get izhuvrlq '\n' ako ima nov red

	return input;
}
