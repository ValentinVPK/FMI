#include "Counter.hpp"

Counter::Counter()
	:value(0), steps(1)
{

}

Counter::Counter(int initial)
	:value(initial), steps(1)
{
}

Counter::Counter(int initial, unsigned step)
	:value(initial), steps(step)
{
}

void Counter::increment()
{
	this->value += this->steps;
}

int Counter::getTotal() const
{
	return this->value;
}

unsigned Counter::getStep() const
{
	return this->steps;
}
