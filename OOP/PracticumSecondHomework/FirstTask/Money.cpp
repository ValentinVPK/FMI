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
#include "Money.hpp"

Money::Money() {
	this->gold_silver.first = 0;
	this->gold_silver.second = 0;
}

Money::Money(const MaterialTypes type, int amount) {
	this->gold_silver.first = 0;
	this->gold_silver.second = 0;
	this->add(amount);
}
Money::Money(const Money& other_money) {
	this->gold_silver = other_money.gold_silver;
}
Money& Money::operator=(const Money& other_money) {
	if (this != &other_money) {
		this->gold_silver = other_money.gold_silver;
	}

	return *this;
}

void Money::add(int amount) {
	for (size_t i = 0; i < amount; i++) {
		this->gold_silver.second++;
		if (this->gold_silver.second == 100) {
			this->gold_silver.first++;
			this->gold_silver.second = 0;
		}
	}
}

void Money::extract(int amount) {
	//When extracted amount is more than available money - set gold and silver to zero
	if (((this->gold_silver.first * 100) + this->gold_silver.second) <= amount){
		this->gold_silver.first = 0;
		this->gold_silver.second = 0;
		return;
	}

	for (size_t i = 0; i < amount; i++)
	{
		this->gold_silver.second--;
		if (this->gold_silver.second == -1) {
			this->gold_silver.first--;
			this->gold_silver.second = 99;
		}
	}
}

MaterialTypes Money::get_type() const {
	return MaterialTypes::other;
}

int Money::calculate_slots_taken() const {
	return 0;
}

int Money::get_amount() const {
	return this->gold_silver.first * 100 + this->gold_silver.second;
}

