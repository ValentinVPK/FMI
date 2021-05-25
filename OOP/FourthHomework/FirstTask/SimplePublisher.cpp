#include "SimplePublisher.hpp"


void SimplePublisher::subscribe(Subscriber* subscriber)
{
	if (subscriber == nullptr) 
	{
		return;
	}

	this->subscribers.push_back(subscriber);
}

void SimplePublisher::unsubscribe(Subscriber* subscriber)
{
	for (size_t i = 0; i < this->subscribers.size(); i++)
	{
		if (subscribers[i]->id == subscriber->id)
		{
			this->subscribers.erase(this->subscribers.begin() + i);
		}
	}
}


void SimplePublisher::signal(Message message)
{
	for (auto subscriber : subscribers)
	{
		subscriber->signal(message);
	}
}
