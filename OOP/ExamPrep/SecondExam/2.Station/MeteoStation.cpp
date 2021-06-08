#include "MeteoStation.hpp"

MeteoStation::MeteoStation(const string& city, const double& cityTemperature)
	:city(city), temperature(temperature)
{
}

MeteoStation::MeteoStation(const MeteoStation& rhs)
{
	this->city = rhs.city;
	this->temperature = rhs.temperature;
	for (auto observer : rhs.observers) 
	{
		this->observers.push_back(observer->clone());
	}
}

MeteoStation& MeteoStation::operator=(const MeteoStation& rhs)
{
	if (this != &rhs) 
	{
		this->city = rhs.city;
		this->temperature = rhs.temperature;

		for (auto observer : this->observers) 
		{
			delete observer;
		}

		this->observers.clear();
		for (auto observer : rhs.observers)
		{
			this->observers.push_back(observer->clone());
		}
	}
}

MeteoStation::~MeteoStation()
{
	for (auto observer : observers) 
	{
		delete observer;
	}
}

string MeteoStation::getCity() const
{
	return this->city;
}

double MeteoStation::getTemperature() const
{
	return this->temperature;
}

void MeteoStation::setTemperature(const double& temprature)
{
	this->temperature = temperature;
	this->notify();
}

void MeteoStation::registeer(Observer* observer)
{
	this->observers.push_back(observer->clone());
	this->observers[this->observers.size() - 1]->update(this->city, this->temperature);
}

void MeteoStation::unregister(const size_t& index)
{
	delete this->observers[index];
	this->observers.erase(observers.begin() + index);
}

void MeteoStation::notify() const
{
	for (auto observer : observers)
	{
		observer->update(this->city, this->temperature);
	}
}
