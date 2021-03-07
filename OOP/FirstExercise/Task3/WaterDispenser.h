#pragma once
class WaterDispenser
{
private:
	double currLiters;
	double maxLiters;
	void setDispenser(double liters);
	void setMaxLiters(double maxLiters);
public:
	WaterDispenser(double liters, double maxLiters);
	double getCurrLiters() const;
	void fillDispenser(double liters);
	void fillCup(unsigned int cupMl);
};

