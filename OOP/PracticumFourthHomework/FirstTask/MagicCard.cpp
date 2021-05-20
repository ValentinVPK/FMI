
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
#include "MagicCard.hpp"

string MagicCard::get_type_as_string() const
{
	if (this->type == CardType::TRAP) 
	{
		return "TRAP";
	}

	if (this->type == CardType::BUFF)
	{
		return "BUFF";
	}

	return "SPELL";
}

void MagicCard::set_type(const string type_str)
{
	if (type_str == "SPELL")
	{
		this->type = CardType::SPELL;
	}

	if (type_str == "TRAP")
	{
		this->type = CardType::TRAP;
	}

	if (type_str == "BUFF")
	{
		this->type == CardType::BUFF;
	}
}

MagicCard::MagicCard(const string init_name, const string init_effect, unsigned int init_rarity, const CardType init_type)
	:Card(init_name, init_effect, init_rarity), type(init_type)
{

}

//MagicCard::MagicCard(const MagicCard& rhs)
//{
//	this->name = rhs.name;
//	this->effect = rhs.effect;
//	this->rarity = rhs.rarity;
//	this->type = rhs.type;	
//}

MagicCard& MagicCard::operator=(const MagicCard& rhs)
{
	if (this != &rhs) 
	{
		Card::operator=(rhs);
		this->type = rhs.type;
	}

	return *this;
}

ostream& MagicCard::print(ostream& output) const
{
	output << name << "|" << effect << "|" << rarity << "|" << get_type_as_string() << "\n";

	return output;
}

istream& MagicCard::load(istream& input)
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
	input >> trash >> rarity >> trash >> new_type;
	input.get();

	set_type(new_type);

	return input;
}

