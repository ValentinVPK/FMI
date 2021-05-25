#include "Repository.hpp"



Repository::Repository()
{
}

Repository::Repository(const Repository& rhs)
{
	for (auto subscriber : rhs.subscribers)
	{
		this->subscribers.push_back(subscriber->clone());
	}
}

Repository& Repository::operator=(const Repository& rhs)
{
	if (this != &rhs)
	{
		for (auto subscriber : subscribers)
		{
			delete subscriber;
		}

		this->subscribers.clear();

		for (auto subscriber : rhs.subscribers)
		{
			this->subscribers.push_back(subscriber->clone());
		}
	}

	return *this;
}

Repository::~Repository()
{
	for (auto subscriber : subscribers)
	{
		delete subscriber;
	}
}

void Repository::add(Subscriber* subscriber)
{
	this->subscribers.push_back(subscriber->clone());
}

Subscriber* Repository::get(string id)
{
	for (auto subscriber : subscribers)
	{
		if (subscriber->id == id)
		{
			return subscriber;
		}
	}

	return nullptr;
}



