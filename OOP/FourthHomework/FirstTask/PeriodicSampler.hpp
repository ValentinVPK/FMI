#pragma once
#include "Subscriber.hpp"

class PeriodicSampler : public Subscriber {
private:
	size_t period;
public:
	PeriodicSampler(std::string id, size_t period);

	int read() const override;

	Subscriber* clone() const override;
};
