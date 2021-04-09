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
#include <iostream>
#include <utility>
#include <string>
using namespace std;

enum class ArmorType {
	cloth, 
	leather, 
	mail
};

class Armor {
private:
	ArmorType type;
	int defence;
	vector<pair<string, double>> effects;
public:
	Armor(const ArmorType type, int defence);
	Armor(const Armor& other_armor);
	Armor& operator=(const Armor& other_armor);

	double get_score() const;

	void add_effect(string effect_name, double effect_power);
	void remove_effect(string effect_name);
	void change_effect_power(string effect_name, double effect_power);
	
};
