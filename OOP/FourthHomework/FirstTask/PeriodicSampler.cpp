#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(std::string id, size_t period)
	:Subscriber(id), period(period)
{
}


int PeriodicSampler::read() const
{
	if (this->messages.size() == 0) 
	{
		return 0;
	}

	for (int i = this->messages.size() - 1; i >= 1; i--)
	{
		if (i % this->period == 0) 
		{
			return this->messages[i].data;
		}
	}

	return this->messages[0].data;
}

Subscriber* PeriodicSampler::clone() const
{
	return new PeriodicSampler(*this);
}
