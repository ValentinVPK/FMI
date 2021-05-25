#pragma once

#include "Subscriber.hpp"

class Averager : public Subscriber {
public:
	Averager(std::string id);

	int read() const override;

	Subscriber* clone() const;
};
