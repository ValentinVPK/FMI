#pragma once
#include "TwowayCounter.hpp"
#include "LimitedCounter.hpp"

class LimitedTwowayCounter : public LimitedCounter, public TwowayCounter{
private:
	int min;
public:
	LimitedTwowayCounter(int min, int max);
	LimitedTwowayCounter(int min, int max, int initial);
	LimitedTwowayCounter(int min, int max, int initial, unsigned step);

	void decrement();

	int getMin() const;
};
