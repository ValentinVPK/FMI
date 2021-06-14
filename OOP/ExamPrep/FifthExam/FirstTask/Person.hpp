#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Person {
private:
	char* firstName = nullptr;
	char* lastName = nullptr;
public:
	Person(const char* firstName = "", const char* lastName = "");
	Person(const Person& rhs);
	Person& operator=(const Person & rhs);
	~Person();

	char* getFirstName() const;
	char* getLastName() const;

	void setFirstName(const char* firstName);
	void setLastName(const char* lastName);

	void writeToFile(const char* fileName);

	friend  ostream& operator<<(ostream& out, const Person& rhs);
	friend istream& operator>>(istream& in, Person& rhs);
};
