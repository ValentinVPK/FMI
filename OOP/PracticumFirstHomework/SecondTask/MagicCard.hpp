/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Valentin Krumov
* @idnumber 62539
* @task 2
* @compiler VC
*/
#pragma once
#include <cstring>
#include <iostream>
using namespace std;

class MagicCard
{
private:
	char name[26];
	char effect[101];
	char type[8];
	bool isBlank;
	void setName(const char* name);
	void setEffect(const char* effect);
	void setType(const char* type);
public:
	MagicCard();
	MagicCard(const char* name, const char* effect, const char* type);
	MagicCard& operator=(const MagicCard& card);

	const char* getName() const;
	const char* getEffect() const;
	const char* getType() const;
	
	bool isCardBlank() const;
};

