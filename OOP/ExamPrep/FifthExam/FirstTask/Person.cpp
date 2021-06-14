#include "Person.hpp"

Person::Person(const char* firstName, const char* lastName)
{
	this->setFirstName(firstName);
	this->setLastName(lastName);
}

Person::Person(const Person& rhs)
{
	this->setFirstName(rhs.firstName);
	this->setLastName(rhs.lastName);
}

Person& Person::operator=(const Person& rhs)
{
	if (this != &rhs) {
		this->setFirstName(rhs.firstName);
		this->setLastName(rhs.lastName);
	}

	return *this;
}

Person::~Person()
{
	delete[] this->firstName;
	delete[] this->lastName;
}

char* Person::getFirstName() const
{
	return this->firstName;
}

char* Person::getLastName() const
{
	return this->lastName;
}

void Person::setFirstName(const char* firstName)
{
	delete[] this->firstName;
	this->firstName = new char[strlen(firstName) + 1];
	strcpy(this->firstName, firstName);
}

void Person::setLastName(const char* lastName)
{
	delete[] this->lastName;
	this->lastName = new char[strlen(lastName) + 1];
	strcpy(this->lastName, lastName);
}

void Person::writeToFile(const char* fileName)
{
	ofstream of(fileName);

	of << this;
}

ostream& operator<<(ostream& out, const Person& rhs)
{
	out << rhs.firstName << " " << rhs.lastName << endl;

	return out;
}

istream& operator>>(istream& in, Person& rhs)
{
	char name[100];

	in >> name;
	
	rhs.setFirstName(name);

	in >> name;

	rhs.setLastName(name);

	return in;
	
}
