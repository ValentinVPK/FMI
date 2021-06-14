#include "Card.hpp"

Card::Card(const string& name, const size_t& cardNumber, const size_t& imageNumber)
	:name(name), cardNumber(cardNumber), imageNumber(imageNumber)
{
}

string Card::get_name() const
{
	return this->name;
}

size_t Card::get_cardNumber() const
{
	return this->cardNumber;
}

size_t Card::get_imageNumber() const
{
	return this->imageNumber;
}

void Card::print() const
{
	cout << "Name: " << this->name << "; Card Number: " << this->cardNumber << "; Image Number: " << this->imageNumber;
}
