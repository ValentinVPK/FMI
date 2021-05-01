/**
* Solution to homework assignment 1
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
using namespace std;

class Card {
protected:
	string name;
	string effect;
public:
	Card(const string init_name = "", const string init_effect = "");
	Card& operator=(const Card& rhs);
};
