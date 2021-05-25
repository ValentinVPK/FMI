#pragma once
#include "Averager.hpp"
#include "Message.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include "Subscriber.hpp"


class SimplePublisher {
private:
	vector<Subscriber*> subscribers;
public:
	// Could be Subscriber*
	void subscribe(Subscriber* subscriber);

	void unsubscribe(Subscriber* subscriber);

	void signal(Message message);
};
