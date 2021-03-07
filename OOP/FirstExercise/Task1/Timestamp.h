#pragma once
#include <string>
#include <iostream>
using namespace std;

class Timestamp
{
private:
	int hours;
	int minutes;
	int seconds;
public:
	Timestamp(int hours, int minutes, int seconds);
	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;
	void setHours(int hours);
	void setMinutes(int minutes);
	void setSeconds(int seconds);
	void printTimestamp() const;
};

