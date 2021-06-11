#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif
#include "Car.hpp"

Car::Car(const string& brand, const string& model, const size_t& year, const string& problem, const ProblemLevel& level, const bool& isPrivatelyOwned)
	:Vehicle(brand, model, year, problem, level), 
	isPrivatelyOwned(isPrivatelyOwned)
{
}

bool Car::getIsPrivatelyOwned() const
{
	return this->isPrivatelyOwned;
}

void Car::changeOwnership()
{
	if (this->isPrivatelyOwned) 
	{
		this->isPrivatelyOwned = false;
	}
	else 
	{
		this->isPrivatelyOwned = true;
	}
}

Vehicle* Car::clone() const
{
	return new Car(*this);
}
