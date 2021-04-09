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
#include <utility>
#include "Materials.hpp"
using namespace std;
class Money {
private:
	pair<int, int> gold_silver;
public:
	Money();
	Money(const MaterialTypes type,int amount);
	Money(const Money& other_money);
	Money& operator=(const Money& other_money);

	void add(int amount);
	void extract(int amount);
	MaterialTypes get_type() const;
	int get_amount() const;
	int calculate_slots_taken() const;
};
