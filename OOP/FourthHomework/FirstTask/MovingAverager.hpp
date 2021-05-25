#pragma once
#include "Subscriber.hpp"

class MovingAverager : public Subscriber {
public:
	MovingAverager(std::string id, size_t windowSize);

	const size_t windowSize;

	int read() const override;

	Subscriber* clone() const;
};
