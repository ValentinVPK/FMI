#pragma once
#include "LimitedTwowayCounter.hpp"

class Semaphore : public LimitedTwowayCounter{
public:
	Semaphore();
	Semaphore(bool isTrue);

	bool isAvailable() const;
	void wait();
	void signal();
};
