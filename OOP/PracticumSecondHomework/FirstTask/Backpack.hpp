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
#include "Money.hpp"
#include "Materials.hpp"

template<typename T>
class Backpack {
private:
	const int max_slots = 16;
	vector<T> items;
public:
	Backpack();
	Backpack(const Backpack<T>& other_backpack);
	Backpack<T>& operator=(const Backpack<T>& other_backpack);

	bool is_empty() const;
	bool is_full() const;
	void clear();
	void add_items(int amount, const MaterialTypes type = MaterialTypes::other);
	void extract_items(int amount, const MaterialTypes type = MaterialTypes::other);
	int get_index_for_type(const MaterialTypes type);
	int get_slots() const;
};

template<typename T>
Backpack<T>::Backpack() { }
template<typename T>
Backpack<T>::Backpack(const Backpack<T>& other_backpack) {
	this->items = other_backpack.items;
}

template<typename T>
Backpack<T>& Backpack<T>::operator=(const Backpack<T>& other_backpack) {
	if (this != &other_backpack) {
		this->items = other_backpack.items;
	}

	return *this;
}

template<typename T>
bool Backpack<T>::is_empty() const{
	return this->get_slots() == 0;
}

template<typename T>
bool Backpack<T>::is_full() const{
	return this->get_slots() == this->max_slots;
}

template<typename T>
void Backpack<T>::clear() {
	this->items.clear();
}

template<typename T>
int Backpack<T>::get_index_for_type(const MaterialTypes type) {
	for (size_t i = 0; i < size(this->items); i++)
	{
		if (this->items[i].get_type() == type) {
			return i;
		}
	}

	return -1;
}

template<typename T>
void Backpack<T>::add_items(int amount,const MaterialTypes type) {
	int index = this->get_index_for_type(type);
	if (index == -1) {
		if (type == MaterialTypes::other) {
			T money(MaterialTypes::other, amount);
			this->items.push_back(money);
		}
		else {
			if (is_full()) {
				cout << "Bag is full! Can't add more items!" << endl;
				return;
			}
			T material(type, amount);
			this->items.push_back(material);
		}
	}
	else {
		int amount_per_slot = 0;
		if (type == MaterialTypes::other) {
			this->items[index].add(amount);
		}
		else {
			if (type == MaterialTypes::essence) {
				amount_per_slot = 10;
			}
			else {
				amount_per_slot = 20;
			}
			for (size_t i = 0; i < amount; i++)
			{
				if (this->items[index].get_amount() % amount_per_slot == 0) {
					if (this->is_full()) {
						cout << "Backpack is full! Can't add more items!" << endl;
						return;
					}
				}
				this->items[index].add(1);
			}
		}
	}
}

template<typename T>
void Backpack<T>::extract_items(int amount, const MaterialTypes type) {
	int index = this->get_index_for_type(type);
	if (index == -1) {
		cout << "Can't find item with this type!";
	}
	else {
		this->items[index].extract(amount);
	}
}

template<typename T>
int Backpack<T>::get_slots() const {
	int slots = 0;
	for (size_t i = 0; i < size(this->items); i++)
	{
		slots += this->items[i].calculate_slots_taken();
	}

	return slots;
}



