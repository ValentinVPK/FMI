#include "MonsterCard.hpp"

MonsterCard::MonsterCard(const string& name, const size_t& cardNumber, const size_t& imageNumber, const size_t& attackPoints, const size_t& deffencePoints)
	:Card(name, cardNumber, imageNumber), attackPoints(attackPoints), deffencePoints(deffencePoints)
{
}

size_t MonsterCard::get_attackPoints() const
{
	return this->attackPoints;
}

size_t MonsterCard::get_deffencePoints() const
{
	return this->deffencePoints;
}

Card* MonsterCard::clone() const
{
	return new MonsterCard(*this);
}

void MonsterCard::print() const
{
	Card::print();
	cout << "; Attack Points: " << this->attackPoints << "; Deffence Points: " << this->deffencePoints << endl;
}
