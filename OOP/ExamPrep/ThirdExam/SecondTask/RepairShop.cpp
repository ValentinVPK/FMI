#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif
#include "RepairShop.hpp"

size_t RepairShop::calcCapacity() const
{
	size_t result = 0;
	for (auto vehicles : vehicles)
	{
		result += (size_t)vehicles->getLevel();
	}

	return result;
}

RepairShop* RepairShop::getInstance()
{
	if (!instance) 
	{
		instance = new RepairShop;
	}
	return instance;
}

RepairShop::RepairShop(const RepairShop& rhs)
{
	for (auto vehicle : rhs.vehicles)
	{
		this->vehicles.push_back(vehicle->clone());
	}
}

RepairShop& RepairShop::operator=(const RepairShop& rhs)
{
	if (this != &rhs) 
	{
		for (auto vehicle : this->vehicles)
		{
			delete vehicle;
		}

		this->vehicles.clear();

		for (auto vehicle : rhs.vehicles)
		{
			this->vehicles.push_back(vehicle->clone());
		}
	}

	return *this;
}

RepairShop::~RepairShop()
{
	for (auto vehicle : this->vehicles)
	{
		delete vehicle;
	}
}

void RepairShop::add(const Vehicle* vehicle)
{
	if (this->calcCapacity() + (size_t)vehicle->getLevel() > MAX_CAPACITY) 
	{
		cout << "Not enough capacity for this vehicle!" << endl;
	}
	else 
	{
		this->vehicles.push_back(vehicle->clone());
	}
}

bool RepairShop::hasCapacity() const
{
	if (calcCapacity() == MAX_CAPACITY) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

RepairShop* RepairShop::instance = 0;
