#include "Averager.hpp"

Averager::Averager(std::string id)
	:Subscriber(id)
{
}


int Averager::read() const
{
	if (this->messages.size() == 0) 
	{
		return 0;
	}

	int sum = 0;
	for (auto message : this->messages) 
	{
		sum += message.data;
	}

	return sum / this->messages.size();
}

Subscriber* Averager::clone() const
{
	return new Averager(*this);
}
