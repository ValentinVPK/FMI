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
#pragma once
#include "MagicCard.hpp"
#include "MonsterCard.hpp"

unsigned int const CARD_CAP = 20;

class Deck
{
private:
	unsigned int monsterCardsCount;
	unsigned int magicCardsCount;
	MonsterCard monsterCards[CARD_CAP];
	MagicCard magicCards[CARD_CAP];
public:
	Deck();
	unsigned int getMagicCardsCount() const;
	unsigned int getMonsterCardsCount() const;

	void addMagicCard(const MagicCard& card);
	void addMonsterCard(const MonsterCard& card);

	void changeMagicCard(const unsigned int index, const MagicCard& newCard);
	void changeMonsterCard(const unsigned int index, const MonsterCard& newCard);

	void printDeck() const;

};

