#include "User.hpp"

void User::add_card(const Card* card)
{
	this->userDeck.add_card(card);
}

void User::print() const
{
	this->userDeck.print();
}
