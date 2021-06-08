#pragma once
#include "Observer.hpp"
#include <iostream>

class NewspaperObserver : public Observer {
public:
	NewspaperObserver(const string& name = "", const string& city = "",
		const double& cityTemperature = 0);

	void update(const string& cityName, const double& cityTemperature);
	Observer* clone() const;

	void printMeteo() const;
};
