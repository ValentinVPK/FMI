#include "WaterDispenser.h"
#include <iostream>
using namespace std;

WaterDispenser::WaterDispenser(double liters, double maxLiters) {
	setDispenser(liters);
	setMaxLiters(maxLiters);
}
double WaterDispenser::getCurrLiters() const {
	return this->currLiters;
}
void WaterDispenser::setMaxLiters(double maxLiters) {
	this->maxLiters = maxLiters;
}
void WaterDispenser::setDispenser(double liters) {
	this->currLiters = liters;
}
void WaterDispenser::fillDispenser(double liters) {
	if (this->currLiters == this->maxLiters) {
		cout << "Dispenser is full" << endl;
		return;
	}

	if ((this->currLiters + liters) > maxLiters) {
		this->currLiters = maxLiters;
		cout << "Filled to max" << endl;
		return;
	}

	cout << "All water is filled" << endl;
	this->currLiters += liters;
}

void WaterDispenser::fillCup(unsigned int cupMl) {
	double liters = cupMl / 1000.0;

	if (this->currLiters < liters) {
		cout << "Not enough water in dispenser" << endl;
		return;
	}
	
	this->currLiters -= liters;
	cout << "Cup filled" << endl;
}
