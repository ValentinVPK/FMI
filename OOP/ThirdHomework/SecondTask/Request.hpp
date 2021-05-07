#pragma once
#include <string>
using namespace std;

class Request {
protected:
	string message;
	string sender;
	static int count;
	int id;
public:
	Request(const string& message, const string& sender);
	string getMessage() const;
	string getSender() const;
	int getCount() const;
	int getID() const;
};
