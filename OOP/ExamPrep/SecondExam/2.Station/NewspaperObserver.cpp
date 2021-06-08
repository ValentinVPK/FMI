#include "NewspaperObserver.hpp"

NewspaperObserver::NewspaperObserver(const string& name, const string& city, const double& temperature)
{
	this->name = name;
	this->city = city;
	this->temperature = temperature;
}

void NewspaperObserver::update(const string& cityName, const double& cityTemperature)
{
	this->city = cityName;
	this->temperature = cityTemperature;
	cout << "Update " << this->name << ": The temperature in " << this->city << " is " << this->temperature;
}

Observer* NewspaperObserver::clone() const
{
	return new NewspaperObserver(*this);
}

void NewspaperObserver::printMeteo() const
{
	cout << "Newspaper " << this->name << ": The temperature in " << 
		this->city << " is " << this->temperature;
}
