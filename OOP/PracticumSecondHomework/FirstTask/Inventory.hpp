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

template<typename T>
class Inventory {
private:
	T inventory;
public:
	Inventory(T init_inventory);
	Inventory(const Inventory<T>& other_inventory);
	Inventory<T>& operator=(const Inventory<T>& other_inventory);
	int get_slots()const;
	
	friend ostream& operator<<<>(ostream& os, const Inventory<T>& rhs);
	friend bool operator==<>(const Inventory<T>& lhs, const Inventory<T>& rhs);
	friend bool operator!=<>(const Inventory<T>& lhs, const Inventory<T>& rhs);
};

template<typename T>
Inventory<T>::Inventory(T init_inventory) {
	this->inventory = init_inventory;
}

template<typename T>
Inventory<T>::Inventory(const Inventory<T>& other_inventory) {
	this->inventory = other_inventory.inventory;
}

template<typename T>
Inventory<T>& Inventory<T>::operator=(const Inventory<T>& other_inventory) {
	if (this != &other_inventory) {
		this->inventory = other_inventory.inventory;
	}

	return *this;
}

template<typename T>
int Inventory<T>::get_slots() const {
	return this->inventory.get_slots();
}

template<typename T>
ostream& operator<<(ostream& os, const Inventory<T>& rhs) {
	os << "Slots taken in the inventory: " << rhs.get_slots();
	return os;
}

template<typename T>
bool operator==(const Inventory<T>& lhs, const Inventory<T>& rhs) {
	return lhs.get_slots() == rhs.get_slots();
}

template<typename T>
bool operator!=(const Inventory<T>& lhs, const Inventory<T>& rhs) {
	return lhs.get_slots() != rhs.get_slots();
}