#pragma once
#include "Observer.hpp"
#include <vector>

class MeteoStation {
private:
	string city;
	double temperature;
	vector<Observer*> observers;
public:
	MeteoStation(const string& city = "", const double& cityTemperature = 0);
	MeteoStation(const MeteoStation& rhs);
	MeteoStation& operator=(const MeteoStation& rhs);
	~MeteoStation();

	string getCity() const;
	double getTemperature() const;
	void setTemperature(const double& temprature);

	void registeer(Observer* observer);
	void unregister(const size_t& index);

	void notify() const;
};
