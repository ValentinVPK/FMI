/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Valentin Krumov
* @idnumber 62539
* @task 2
* @compiler VC
*/
#include "Deck.hpp"

Deck::Deck() {
	this->monsterCardsCount = 0;
	this->magicCardsCount = 0;
}

void Deck::addMagicCard(const MagicCard& card) {
	if(card.getType() )

	for (size_t i = 0; i < CARD_CAP; i++)
	{
		if (magicCards[i].isCardBlank() && !card.isCardBlank()) {
			magicCards[i] = card;
			++magicCardsCount;
			return;
		}
	}

	cout << "No more space for a magic card!" << endl;
}

void Deck::addMonsterCard(const MonsterCard& card) {
	for (size_t i = 0; i < CARD_CAP; i++)
	{
		if (monsterCards[i].isCardBlank() && !card.isCardBlank()) {
			monsterCards[i] = card;
			++monsterCardsCount;
			return;
		}
	}

	cout << "No more space for a monster card!";
}

void Deck::changeMagicCard(const unsigned int index, const MagicCard& newCard) {
	if (magicCards[index].isCardBlank() && !newCard.isCardBlank()) {
		++magicCardsCount;
	}

	magicCards[index] = newCard;
}

void Deck::changeMonsterCard(const unsigned int index, const MonsterCard& newCard) {
	if (monsterCards[index].isCardBlank() && !newCard.isCardBlank()) {
		++monsterCardsCount;
	}

	monsterCards[index] = newCard;
}

unsigned int Deck::getMagicCardsCount() const{
	return this->magicCardsCount;
}

unsigned int Deck::getMonsterCardsCount() const {
	return this->monsterCardsCount;
}

void Deck::printDeck() const {

	cout << "Monster Cards:" << endl;
	for (size_t i = 0; i < CARD_CAP; i++)
	{
		cout<< i + 1 << ".Name: " << monsterCards[i].getName() << " |AttackPoints: " << monsterCards[i].getAttackPoints() << " |DeffencePoints: " << monsterCards[i].getDeffencePoints() << endl;
	}

	cout << "Magic Cards:" << endl;
	for (size_t i = 0; i < CARD_CAP; i++)
	{
		cout << i + 1 << ".Name: " << magicCards[i].getName() << " |Effect: " << magicCards[i].getEffect() << " |Type: " << magicCards[i].getType() << endl;
	}
}
