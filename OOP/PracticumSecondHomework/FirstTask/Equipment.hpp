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
#pragma once
#include <vector>
#include "Armor.hpp"
#include "Weapon.hpp"
using namespace std;

template<typename T>
class Equipment {
private:
	const int max_slots = 24;
	vector<T> equipment;

public:
	Equipment();
	Equipment(const Equipment<T>& other_equipment);
	Equipment<T>& operator=(const Equipment<T>& other_equipment);
	bool is_full() const;
	bool is_empty() const;
	void clear();
	void add(const T& gear);
	void remove(int index);
	T get_best() const;
	int get_slots() const;

	//double calculate_score();
	friend bool operator==<>(const Equipment<T>& lhs, const Equipment<T>& rhs);
	friend bool operator!=<>(const Equipment<T>& lhs, const Equipment<T>& rhs);
};

template<typename T>
Equipment<T>::Equipment() { }

template<typename T>
Equipment<T>::Equipment(const Equipment<T>& other_equipment) {
	this->equipment = other_equipment.equipment;
}

template<typename T>
Equipment<T>& Equipment<T>::operator=(const Equipment<T>& other_equipment) {
	if (this != &other_equipment) {
		this->equipment = other_equipment.equipment;
	}

	return *this;
}

template<typename T>
bool Equipment<T>::is_full() const {
	return size(this->equipment) == max_slots;
}


template<typename T>
bool Equipment<T>::is_empty() const {
	return size(this->equipment) == 0;
}

template<typename T>
void Equipment<T>::clear() {
	this->equipment.clear();
}

template<typename T>
void Equipment<T>::add(const T& gear) {
	if (size(this->equipment) == max_slots) {
		cout << "Inventory is full! Can't add more equipment!";
		return;
	}

	this->equipment.push_back(gear);
}

template<typename T>
void Equipment<T>::remove(int index) {
	if (index < 0 || index >= size(equipment)) {
		cout << "Invalid index";
		return;
	}

	this->equipment.erase(this->equipment.begin() + index);
}

template<typename T>
T Equipment<T>::get_best() const {
	int best_index = 0;
	double best_score = this->equipment[0].get_score();
	for (size_t i = 0; i < size(equipment); i++) {
		if (this->equipment[i].get_score() > best_score) {
			best_score = this->equipment[i].get_score();
			best_index = i;
		}
	}

	return this->equipment[best_index];
}


template<typename T>
int Equipment<T>::get_slots() const {
	return size(this->equipment);
}

template<typename T>
bool operator==(const Equipment<T>& lhs, const Equipment<T>& rhs) {
	// If one or two of the equipment's vectors are empty
	if (lhs.is_empty() && rhs.is_empty()) {
		return true;
	}
	else if (lhs.is_empty() && !rhs.is_empty()) {
		return false;
	}
	else if (!lhs.is_empty() && rhs.is_empty()) {
		return false;
	}
	//If none of them are empty get_best() will work
	//Compared by the score of the best weapon/armor
	return lhs.get_best().get_score() == rhs.get_best().get_score();
}

template<typename T>
bool operator!=(const Equipment<T>& lhs, const Equipment<T>& rhs) {
	// If one or two of the equipment's vectors are empty
	if (lhs.is_empty() && rhs.is_empty()) {
		return false;
	}
	else if (lhs.is_empty() && !rhs.is_empty()) {
		return true;
	}
	else if (!lhs.is_empty() && rhs.is_empty()) {
		return true;
	}

	//If none of them are empty get_best() will work
	//Compared by the score of the best weapon/armor
	return lhs.get_best().get_score() != rhs.get_best().get_score();
}
