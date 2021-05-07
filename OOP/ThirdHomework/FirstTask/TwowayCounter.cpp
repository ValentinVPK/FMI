#include "TwowayCounter.hpp"

TwowayCounter::TwowayCounter()
	:Counter()
{
}

TwowayCounter::TwowayCounter(int initial)
	:Counter(initial)
{
}

TwowayCounter::TwowayCounter(int initial, unsigned step)
	:Counter(initial,step)
{
}

void TwowayCounter::decrement()
{
	this->value -= this->steps;
}
