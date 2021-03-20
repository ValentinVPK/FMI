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
#include "Date.hpp"

Date::Date() {
	this->day = 1;
	this->month = 1;
	this->year = 2000;
	setDaysInMonth();
}

Date::Date(const unsigned int day, const unsigned int month, const unsigned int year) {
	this->day = day;
	this->month = month;
	this->year = year;
	setDaysInMonth();
}

void Date::addDays(const unsigned int days) {
	for (int i = 0; i < days; i++) {
		day++;
		if (day == daysInMonth + 1) {
			day = 1;
			month++;
			setDaysInMonth();
		}
		if (month == 13) {
			month = 1;
			year++;
			setDaysInMonth();
		}
	}
}
void Date::removeDays(const unsigned int days) {
	for (int i = 0; i < days; i++) {
		day--;
		if (day == 0) {
			switch (month) {
				case 1:
					day = 31;
					break;
				case 3:
					if (isLeapYear()) {
						day = 29;
					}
					else {
						day = 28;
					}
					break;
				case 8:
					day = 31;
					break;
				case 5:
				case 7:
				case 10:
				case 12:
					day = 30;
					break;
				case 2:
				case 4:
				case 6:
				case 9:
				case 11:
					day = 31;
					break;
			}

			month--;
			if (month == 0) {
				month = 12;
				year--;
			}
			setDaysInMonth();
		}
	}
}

bool Date::isLeapYear() {
	return this->year % 4 == 0;
}

bool Date::isLaterThen(const Date& date) {
	if (this->year < date.year) {
		return true;
	}
	
	if (this->year == date.year) {
		if (this->month < date.month) {
			return true;
		}

		if (this->month == date.month) {
			if (this->day < date.day) {
				return true;
			}
		}
	}

	return false;
}

unsigned int Date::daysToXmas() {
	Date tempDate(this->day, this->month, this->year);
	unsigned int days = 0;
	while (true) {
		if (tempDate.day == 25 && tempDate.month == 12) {
			break;
		}
		tempDate.addDays(1);
		days++;
	}

	return days;
}

unsigned int Date::daysBetweenDate(const Date& date) {
	Date tempDate(this->day, this->month, this->year);
	unsigned int days = 0;
	while (true) {
		if (tempDate.day == date.day && tempDate.month == date.month && tempDate.year == date.year) {
			break;
		}
		tempDate.addDays(1);
		days++;
	}

	return days;
}

void Date::printDate() {
	if (day < 10 && month < 10) {
		cout << "0" << day << ".0" << month << "." << year << endl;
		return;
	}
	
	if (day < 10) {
		cout << "0" << day << "." << month << "." << year << endl;
		return;
	}

	if (month < 10) {
		cout << day << ".0" << month << "." << year << endl;
		return;
	}

	cout << day << "." << month << "." << year << endl;
}


void Date::setDaysInMonth() {
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			daysInMonth = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			daysInMonth = 30;
			break;
		case 2:
			daysInMonth = 28;
			if (isLeapYear()) {
				daysInMonth = 29;
			}
			break;	
	}
}
