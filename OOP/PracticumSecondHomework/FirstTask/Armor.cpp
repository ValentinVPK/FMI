/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Valentin Krumov
* @idnumber 62539
* @task 1
* @compiler VC
*/
#include "Armor.hpp"

Armor::Armor(const ArmorType type, int defence) {
	this->type = type;
	this->defence = defence;
}

Armor::Armor(const Armor& other_armor) {
	this->type = other_armor.type;
	this->defence = other_armor.defence;
	this->effects = other_armor.effects;
}

Armor& Armor::operator=(const Armor& other_armor) {
	if (this != &other_armor) {
		this->type = other_armor.type;
		this->defence = other_armor.defence;
		this->effects = other_armor.effects;
	}

	return *this;
}

double Armor::get_score() const {
	double result = 0;

	for (size_t i = 0; i < size(effects); i++)
	{
		result += effects[i].second;
	}

	return result;
}

void Armor::add_effect(string effect_name, double effect_power) {
	// If effect already in effects change its power
	for (size_t i = 0; i < size(this->effects); i++) {
		if (this->effects[i].first == effect_name) {
			this->effects[i].second = effect_power;
			return;
		}
	}

	pair<string, double> effect(effect_name, effect_power);
	this->effects.push_back(effect);
}

void Armor::remove_effect(string effect_name) {
	for (size_t i = 0; i < size(effects); i++) {
		if (effects[i].first == effect_name) {
			this->effects.erase(effects.begin() + i);
			return;
		}
	}

	cout << "Can't find effect with name: " << effect_name << endl;
}

void Armor::change_effect_power(string effect_name, double effect_power) {
	for (size_t i = 0; i < size(effects); i++) {
		if (effects[i].first == effect_name) {
			effects[i].second = effect_power;
			return;
		}
	}

	cout << "Can't find effect with name: " << effect_name << endl;
}
