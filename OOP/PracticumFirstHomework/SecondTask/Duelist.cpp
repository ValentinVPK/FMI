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
#include "Duelist.hpp"

Duelist::Duelist(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Duelist::Duelist(const Duelist& anotherDuelist) {
	this->deck = anotherDuelist.deck;
	this->name = new char[strlen(anotherDuelist.name) + 1];
	strcpy(this->name, anotherDuelist.name);
}
Duelist::~Duelist() {
	delete [] this->name;
}
Duelist& Duelist::operator=(const Duelist& anotherDuelist) {
	if (this != &anotherDuelist) {
		delete [] this->name;

		this->deck = anotherDuelist.deck;
		this->name = new char[strlen(anotherDuelist.name) + 1];
		strcpy(this->name, anotherDuelist.name);
	}

	return *this;
}

unsigned int Duelist::getMagicCardsCountInDeck() const {
	return deck.getMagicCardsCount();
}
unsigned int Duelist::getMonsterCardsCountInDeck() const {
	return deck.getMonsterCardsCount();
}

void Duelist::addMagicCardInDeck(const MagicCard& card) {
	deck.addMagicCard(card);
}
void Duelist::addMonsterCardInDeck(const MonsterCard& card) {
	deck.addMonsterCard(card);
}

void Duelist::changeMagicCardInDeck(unsigned int index, const MagicCard& newCard) {
	deck.changeMagicCard(index, newCard);
}
void Duelist::changeMonsterCardInDeck(unsigned int index, const MonsterCard& newCard) {
	deck.changeMonsterCard(index, newCard);
}

void Duelist::printDuelistAndDeck() const {
	cout << "Duelist: " << this->name << endl;
	deck.printDeck();
}
