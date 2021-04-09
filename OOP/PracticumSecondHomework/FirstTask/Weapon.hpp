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
#include <string>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

enum class WeaponType {
	one_handed,
	two_handed
};

enum class WeaponKind {
	axe, // can be one AND two handed
	sword, // can be one AND two handed
	dagger, // can be ONLY one handed
	mace, // can be ONLY one handed
	staff,// can be ONLY two handed
	// etc - can be expanded with other kinds of weapons
};

class Weapon {
private:
	WeaponType type;
	WeaponKind kind;
	pair<double,double> hit_damage;
	vector<pair<string, double>> effects;

	void set_type(const WeaponType type);
public:
	Weapon(const WeaponKind kind,const WeaponType type, double min_hit_damage,
		double max_hit_damage);
	Weapon(const Weapon& other_weapon);
	Weapon& operator=(const Weapon& other_weapon);
	
	double get_score() const;
	void change_kind(WeaponKind new_kind);
	void change_type();
	void add_effect(string effect_name, double effect_power);
	void remove_effect(string effect_name);
	void change_effect_power(string effect_name, double effect_power);
};
