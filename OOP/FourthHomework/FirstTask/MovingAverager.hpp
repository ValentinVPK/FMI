#pragma once
#include "Subscriber.hpp"

class MovingAverager : public Subscriber {
public:
	MovingAverager(std::string id, size_t windowSize);

	const size_t windowSize;

	void signal(Message message) override;

	int read() const override;

	Subscriber* clone() const;
};
