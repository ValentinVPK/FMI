#pragma once
#include <string>
using namespace std;

class Observer {
protected:
	string name;
	string city;
	double temperature;
public:
	virtual ~Observer() = default;

	virtual void update(const string& cityName, const double& cityTemperature) = 0;
	virtual Observer* clone() const = 0;

};