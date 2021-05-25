#pragma once

#include "Averager.hpp"
#include "Message.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"


class BacklogPublisher {
private:
	vector<Message> messagesSent;
	vector<Subscriber*> subscribers;
public:

	void subscribe(Subscriber* subscriber);

	void unsubscribe(Subscriber* subscriber);

	void signal(Message message);
};
