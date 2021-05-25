#pragma once
#include "Subscriber.hpp"
#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"

class Repository {
private:
	vector<Subscriber*> subscribers;
public:
	Repository();
	Repository(const Repository& rhs);
	Repository& operator=(const Repository& rhs);
	~Repository();

	void add(Subscriber* subscriber);
	
	Subscriber* get(string id);
};
