#include "LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max)
	:Counter(), LimitedCounter(max), TwowayCounter(), min(min)
{
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial)
	:Counter(initial), LimitedCounter(max, initial), TwowayCounter(initial), min(min)
{
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial, unsigned step)
	:Counter(initial,step),
	LimitedCounter(max, initial, step),
	TwowayCounter(initial,step),
	min(min)
{
}

void LimitedTwowayCounter::decrement()
{
	if(this->value - (int)this->steps >= this->min)
	{
		TwowayCounter::decrement();
	}
}

int LimitedTwowayCounter::getMin() const
{
	return this->min;
}
