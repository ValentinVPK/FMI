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
class MonsterCard
{
private:
	char name[26];
	unsigned int attackPoints;
	unsigned int deffencePoints;
	bool isBlank;
	void setName(const char* name);
	void setAttackPoints(const unsigned int attackPoints);
	void setDeffencePoints(const unsigned int deffencePoints);
public:
	MonsterCard();
	MonsterCard(const char* name,const unsigned int attackPoints, const unsigned int deffencePoints);
	MonsterCard& operator=(const MonsterCard& card);

	const char* getName() const;
	unsigned int getAttackPoints() const;
	unsigned int getDeffencePoints() const;
		
	bool isCardBlank() const;
};

