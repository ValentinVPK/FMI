#include "LimitedCounter.hpp"

LimitedCounter::LimitedCounter(int max)
	:Counter(), max(max)
{

}

LimitedCounter::LimitedCounter(int max, int initial)
	:Counter(initial), max(max)
{
}

LimitedCounter::LimitedCounter(int max, int initial, unsigned step)
	:Counter(initial,step), max(max)
{
}

int LimitedCounter::getMax() const
{
	return this->max;
}

void LimitedCounter::increment()
{
	if(this->value + (int)this->steps <= this->max)
	{
		Counter::increment();
	}
}

