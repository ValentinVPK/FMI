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
#include <iostream>
using namespace std;
class Date
{
private:
	unsigned int daysInMonth;
	unsigned int day;
	unsigned int month;
	unsigned int year;
	void setDaysInMonth();
public:
	Date();
	Date(const unsigned int day, const unsigned int month, const unsigned int year);
	void addDays(const unsigned int days);
	void removeDays(const unsigned int days);
	unsigned int daysToXmas();
	unsigned int daysBetweenDate(const Date& date);
	bool isLeapYear();
	bool isLaterThen(const Date& date);
	void printDate();
};

