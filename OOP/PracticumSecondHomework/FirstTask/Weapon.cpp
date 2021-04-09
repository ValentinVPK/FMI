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
#include "Weapon.hpp"

Weapon::Weapon(const WeaponKind kind, const WeaponType type, double min_hit_damage,
	double max_hit_damage) {
	this->kind = kind;
	//Setting the type according to the kind
	this->set_type(type);
	this->hit_damage.first = min_hit_damage;
	this->hit_damage.second = max_hit_damage;
}

Weapon::Weapon(const Weapon& other_weapon) {
	this->kind = other_weapon.kind;
	this->type = other_weapon.type;
	this->hit_damage = other_weapon.hit_damage;
	this->effects = other_weapon.effects;
}

Weapon& Weapon::operator=(const Weapon& other_weapon) {
	if (this != &other_weapon) {
		this->kind = other_weapon.kind;
		this->type = other_weapon.type;
		this->hit_damage = other_weapon.hit_damage;
		this->effects = other_weapon.effects;
	}

	return *this;
}

double Weapon::get_score() const {
	double result = 0;
	result += (this->hit_damage.first + this->hit_damage.second) / 2.0;
	for (size_t i = 0; i < size(effects); i++)
	{
		result += effects[i].second;
	}

	if (this->type == WeaponType::one_handed) {
		result *= 0.75;
	}
	else if (this->type == WeaponType::two_handed) {
		result *= 1.5;
	}

	return result;
}

void Weapon::change_kind(WeaponKind new_kind) {
	this->kind = new_kind;
	this->set_type(this->type);
	
}

void Weapon::change_type() {
	// Can only change types on sword and axe
	if (this->kind == WeaponKind::sword || this->kind == WeaponKind::axe || 
		this->kind == WeaponKind::mace) {
		if (this->type == WeaponType::one_handed) {
			this->type = WeaponType::two_handed;
		}
		else if (this->type == WeaponType::two_handed) {
			this->type = WeaponType::one_handed;
		}
	}
	else if(this->kind == WeaponKind::staff){
		cout << "Can't change the type for staff!" << endl;
	}
	else if (this->kind == WeaponKind::dagger) {
		cout << "Can't change the type for dagger!" << endl;
	}
}


void Weapon::add_effect(string effect_name, double effect_power) {

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

void Weapon::remove_effect(string effect_name) {
	
	for (size_t i = 0; i < size(effects); i++) {
		if (effects[i].first == effect_name) {
			this->effects.erase(effects.begin() + i);
			return;
		}
	}

	cout << "Can't find effect with name: " << effect_name << endl;
}

void Weapon::change_effect_power(string effect_name, double effect_power) {
	for (size_t i = 0; i < size(effects); i++) {
		if (effects[i].first == effect_name) {
			effects[i].second = effect_power;
			return;
		}
	}

	cout << "Can't find effect with name: " << effect_name << endl;
}

void Weapon::set_type(const WeaponType type) {
	switch (this->kind) {
		case(WeaponKind::dagger):
			if (type == WeaponType::two_handed) {
				cout << "Converting dagger type to one-handed!" << endl;
			}
			this->type = WeaponType::one_handed;
			break;
		case(WeaponKind::staff):
			if (type == WeaponType::one_handed) {
				cout << "Converting staff type to two-handed!" << endl;
			}
			this->type = WeaponType::two_handed;
			break;
		default:
			this->type = type;
			// Don't need to check for type because the axe,sword, mace can be both types
			break;
	}
}