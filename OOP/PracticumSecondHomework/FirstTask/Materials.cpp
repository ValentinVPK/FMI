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
#include "Materials.hpp";

Materials::Materials(const MaterialTypes type, int amount) {
	this->type = type;
	this->amount = amount;
}

Materials::Materials(const Materials& other_materials) {
	this->type = other_materials.type;
	this->amount = other_materials.amount;
}

Materials& Materials::operator=(const Materials& other_materials) {
	if (this != &other_materials) {
		this->type = other_materials.type;
		this->amount = other_materials.amount;
	}

	return *this;
}

void Materials::add(int amount_to_add) {
	this->amount += amount_to_add;
}

void Materials::extract(int amount_to_extract) {
	if (this->amount < amount_to_extract) {
		this->amount = 0;
		return;
	}

	this->amount -= amount_to_extract;
}

MaterialTypes Materials::get_type() const {
	return this->type;
}

int Materials::get_amount() const {
	return this->amount;
}

int Materials::calculate_slots_taken() const {
	int amount_tmp = this->amount;
	int slots = 0;
	while (amount_tmp > 0) {
		if (this->type == MaterialTypes::essence) {
			slots++;
			amount_tmp -= 10;
		}
		else {
			slots++;
			amount_tmp -= 20;
		}
	}

	return slots;
}


