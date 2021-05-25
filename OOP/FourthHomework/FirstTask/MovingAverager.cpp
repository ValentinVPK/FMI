#include "MovingAverager.hpp"

MovingAverager::MovingAverager(std::string id, size_t windowSize)
	:Subscriber(id), windowSize(windowSize)
{
}


int MovingAverager::read() const
{
	if (this->messages.size() == 0) 
	{
		return 0;
	}

	int sum = 0;
	size_t windowSizeTmp = this->windowSize;

	for (int i = this->messages.size() - 1; i >=0 ; i--)
	{
		if (windowSizeTmp == 0) 
		{
			return sum / this->windowSize;
		}

		sum += this->messages[i].data;
		windowSizeTmp--;
	}

	return sum / this->messages.size();
}

Subscriber* MovingAverager::clone() const
{
	return new MovingAverager(*this);
}
