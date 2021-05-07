#include "Semaphore.hpp"

Semaphore::Semaphore()
	:LimitedTwowayCounter(0, 1)
{

}

Semaphore::Semaphore(bool isTrue)
	:LimitedTwowayCounter(0,1)
{
	if (isTrue) 
	{
		this->value = 1;
	}
	else 
	{
		this->value = 0;
	}
}

bool Semaphore::isAvailable() const
{
	if (this->value == 1) 
	{
		return true;
	}

	return false;
}

void Semaphore::wait()
{
	LimitedTwowayCounter::decrement();
}

void Semaphore::signal()
{
	LimitedTwowayCounter::increment();
}
