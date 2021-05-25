#include "Subscriber.hpp"

Subscriber::Subscriber()
	:id("")
{
}

Subscriber::Subscriber(string id)
	:id(id)
{
}

void Subscriber::signal(Message message)
{
	this->messages.push_back(message);
}

Subscriber::~Subscriber()
{

}
