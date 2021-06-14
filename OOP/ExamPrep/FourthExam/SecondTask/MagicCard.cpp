#include "MagicCard.hpp"

MagicCard::MagicCard(const string& name, const size_t& cardNumber, const size_t& imageNumber, const string& effect)
	:Card(name, cardNumber, imageNumber), effect(effect)
{
}

string MagicCard::get_effect() const
{
	return this->effect;
}

Card* MagicCard::clone() const
{
	return new MagicCard(*this);
}

void MagicCard::print() const
{
	Card::print();
	cout << "; Effect: " << this->effect << endl;
}
