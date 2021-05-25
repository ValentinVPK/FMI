#include "BacklogPublisher.hpp"

void BacklogPublisher::subscribe(Subscriber* subscriber)
{
	for (auto message : messagesSent)
	{
		subscriber->signal(message);
	}

	this->subscribers.push_back(subscriber);
}

void BacklogPublisher::unsubscribe(Subscriber* subscriber)
{
	for (size_t i = 0; i < this->subscribers.size(); i++)
	{
		if (subscribers[i]->id == subscriber->id)
		{
			this->subscribers.erase(this->subscribers.begin() + i);
		}
	}
}

void BacklogPublisher::signal(Message message)
{
	this->messagesSent.push_back(message);

	for (auto subscriber : subscribers)
	{
		subscriber->signal(message);
	}
}
