#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif
#include "Bus.h"

Bus::Bus(const string& brand, const string& model, const size_t& year, const string& problem, const ProblemLevel& level, const bool& hasPassengers)
	:Vehicle(brand, model, year, problem, level),
	hasPassengers(hasPassengers)
{
}

bool Bus::getHasPassengers() const
{
	return this->hasPassengers;
}

void Bus::changePassengers()
{
	if (this->hasPassengers)
	{
		this->hasPassengers = false;
	}
	else
	{
		this->hasPassengers = true;
	}
}

Vehicle* Bus::clone() const
{
	return new Bus(*this);
}
