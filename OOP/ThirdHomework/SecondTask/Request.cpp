
#include "Request.hpp"

Request::Request(const string& message, const string& sender)
{
	this->message = message;
	this->sender = sender;
	this->count++;
	this->id = this->count;
}

string Request::getMessage() const
{
	return this->message;
}

string Request::getSender() const
{
	return this->sender;
}

int Request::getCount() const
{
	return this->count;
}

int Request::getID() const
{
	return this->id;
}

int Request::count = 0;
