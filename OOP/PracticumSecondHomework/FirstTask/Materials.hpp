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
#include <vector>
#include <iostream>
using namespace std;
enum class MaterialTypes {
	herbs,
	ores,
	cloth,
	essence,
	other // this one is gonna be used for money
};

class Materials {
private:
	MaterialTypes type;
	int amount;
public:
	Materials(const MaterialTypes type, int amount);
	Materials(const Materials& other_materials);
	Materials& operator=(const Materials& other_materials);

	void add(int amount_to_add);
	void extract(int amount_to_extract);
	
	MaterialTypes get_type() const;
	int get_amount() const;
	int calculate_slots_taken() const;
};

