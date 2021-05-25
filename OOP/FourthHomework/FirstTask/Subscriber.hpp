#pragma once
#include <string>
#include <vector>
#include "Message.hpp"
using namespace std;

class Subscriber {
protected:
	vector<Message> messages;
public:
	const string id;

	Subscriber();
	Subscriber(string id);

	void signal(Message message); 

	virtual int read() const = 0;

	virtual Subscriber* clone() const = 0;

	virtual ~Subscriber();
};
