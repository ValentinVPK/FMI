#include "Timestamp.h"
#include <iostream>
using namespace std;

int Timestamp::getHours() const{
	return this->hours;
}
int Timestamp::getMinutes() const {
	return this->minutes;
}
int Timestamp::getSeconds() const {
	return this->seconds;
}
void Timestamp::setHours(int hours) {
	if (hours < 0) {
		cout << "Invalid hours";
		return;
	}

	this->hours = hours;
}
void Timestamp::setMinutes(int minutes) {
	if (minutes < 0) {
		cout << "Invalid minutes";
		return;
	}

	this->minutes = minutes;
}
void Timestamp::setSeconds(int seconds) {
	if (seconds < 0) {
		cout << "Invalid seconds";
		return;
	}

	this->seconds = seconds;
}

 Timestamp::Timestamp(int hours, int minutes, int seconds) {
	 setHours(hours);
	 setMinutes(minutes);
	 setSeconds(seconds);
}

void Timestamp::printTimestamp() const {
	cout << this->hours << ":" << this->minutes << ":" << this->seconds << endl;
}


