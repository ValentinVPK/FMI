#include "SpecialCard.hpp"

SpecialCard::SpecialCard(const string& name, const size_t& cardNumber, const size_t& imageNumber, const size_t& attackPoints, const size_t& deffencePoints, const string& effect, const size_t& level)
	:Card(name, cardNumber, imageNumber), 
	MonsterCard(name, cardNumber, imageNumber, attackPoints, deffencePoints),
	MagicCard(name, cardNumber, imageNumber, effect),
	level(level)
{
}

size_t SpecialCard::get_level() const
{
	return this->level;
}

Card* SpecialCard::clone() const
{
	return new SpecialCard(*this);
}

void SpecialCard::print() const
{
	MonsterCard::print();
	cout << "; Effect: " << this->effect << "; Level: " << this->level << endl;
}
