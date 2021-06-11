#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif
#include "Vehicle.hpp"

Vehicle::Vehicle(const string& brand, const string& model, const size_t& year, const string& problem, const ProblemLevel& level)
	:brand(brand), model(model), year(year), problem(problem), level(level)
{
}


string Vehicle::getBrand() const
{
	return this->brand;
}


string Vehicle::getModel() const
{
	return this->model;
}

size_t Vehicle::getYear() const
{
	return this->year;
}

string Vehicle::getProblem() const
{
	return this->problem;
}

ProblemLevel Vehicle::getLevel() const
{
	return this->level;
}


void Vehicle::setBrand(const string& brand)
{
	 this->brand = brand;
}


void Vehicle::setModel(const string& model)
{
	this->model = model;
}

void Vehicle::setYear(const size_t& year)
{
	this->year = year;
}

void Vehicle::setProblem(const string& problem)
{
	this->problem = problem;
}

void Vehicle::setLevel(const ProblemLevel& level)
{
	this->level = level;
}
