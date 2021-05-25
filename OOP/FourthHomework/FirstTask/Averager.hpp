#pragma once

#include "Subscriber.hpp"

class Averager : public Subscriber {
public:
	Averager(std::string id);

	void signal(Message message) override;

	int read() const override;

	Subscriber* clone() const;
};
