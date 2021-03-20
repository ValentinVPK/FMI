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
#include "MagicCard.hpp"

MagicCard::MagicCard() {
	setName("Blank Magic Card");
	setEffect("No effect");
	setType("No type");
	this->isBlank = true;
}
MagicCard::MagicCard(const char* name, const char* effect, const char* type) {
	if (type != "spell" && type != "trap" && type != "buff") {
		setName("Blank Magic Card");
		setEffect("No effect");
		setType("No type");
		this->isBlank = true;
	}
	else {
		setName(name);
		setEffect(effect);
		setType(type);
		this->isBlank = false;
	}
}

MagicCard& MagicCard::operator=(const MagicCard& card) {
	if (this != &card) {
		this->isBlank = card.isBlank;
		setName(card.name);
		setEffect(card.effect);
		setType(card.type);
	}
	return *this;
}

bool MagicCard::isCardBlank() const {
	return this->isBlank;
}
const char* MagicCard::getName() const {
	return this->name;
}
const char* MagicCard::getEffect() const {
	return this->effect;
}
const char* MagicCard::getType() const {
	return this->type;
}

void MagicCard::setName(const char* name) {
	strcpy(this->name, name);
}

void MagicCard::setEffect(const char* effect) {
	strcpy(this->effect, effect);
}

void MagicCard::setType(const char* type) {
	strcpy(this->type, type);
}