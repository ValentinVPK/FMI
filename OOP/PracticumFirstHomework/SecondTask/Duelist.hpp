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
#include "Deck.hpp"
#include <cstring>

class Duelist
{
private:
	char* name;
	Deck deck;
public:
	Duelist(const char* name = "No Name");
	Duelist(const Duelist& anotherDuelist);
	Duelist& operator=(const Duelist& anotherDuelist);
	~Duelist();

	unsigned int getMagicCardsCountInDeck() const;
	unsigned int getMonsterCardsCountInDeck() const;

	void addMagicCardInDeck(const MagicCard& card);
	void addMonsterCardInDeck(const MonsterCard& card);

	void changeMagicCardInDeck(unsigned int index, const MagicCard& newCard);
	void changeMonsterCardInDeck(unsigned int index, const MonsterCard& newCard);

	void printDuelistAndDeck() const;
};

