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

#include "MonsterCard.hpp"

MonsterCard::MonsterCard() {
	setName("Blank Monster Card");
	setAttackPoints(0);
	setDeffencePoints(0);
	this->isBlank = true;
}
MonsterCard::MonsterCard(const char* name, const unsigned int attackPoints, const unsigned int deffencePoints) {
	setName(name);
	setAttackPoints(attackPoints);
	setDeffencePoints(deffencePoints);
	this->isBlank = false;
}

MonsterCard& MonsterCard::operator=(const MonsterCard& card) {
	if (this != &card) {
		this->isBlank = card.isBlank;
		setName(card.name);
		setAttackPoints(card.attackPoints);
		setDeffencePoints(card.deffencePoints);
	}

	return *this;
}

bool MonsterCard::isCardBlank() const {
	return this->isBlank;
}

const char* MonsterCard::getName() const{
	return this->name;
}

unsigned int MonsterCard::getAttackPoints() const {
	return this->attackPoints;
}

unsigned int MonsterCard::getDeffencePoints() const {
	return this->deffencePoints;
}

void MonsterCard::setName(const char* name) {
	strcpy(this->name, name);
}

void MonsterCard::setAttackPoints(const unsigned int attackPoints) {
	this->attackPoints = attackPoints;
}

void MonsterCard::setDeffencePoints(const unsigned int deffencePoints) {
	this->deffencePoints = deffencePoints;
}
