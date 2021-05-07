#pragma once
#include "Counter.hpp"

class LimitedCounter : virtual public Counter{
protected:
	int max;
public:
	LimitedCounter(int max);
	LimitedCounter(int max, int initial);
	LimitedCounter(int max, int initial, unsigned step);

	int getMax() const;
	void increment();

};
