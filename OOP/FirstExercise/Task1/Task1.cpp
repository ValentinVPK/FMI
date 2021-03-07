
#include <iostream>
#include "Timestamp.h"

using namespace std;

Timestamp turnIntoTimestamp(int allSeconds) {
	int hours = allSeconds / 3600;
	int minutes = (allSeconds % 3600) / 60;
	int seconds = allSeconds % 60;

	Timestamp newTimestamp(hours, minutes, seconds);

	return newTimestamp;
}

int turnIntoSeconds(Timestamp timestamp) {
	return timestamp.getHours() * 3600 + timestamp.getMinutes() * 60 + 
		timestamp.getSeconds();
}

Timestamp addTwoTimestamps(const Timestamp timestamp1,const Timestamp timestamp2) {
	int allSeconds = (timestamp1.getHours() + timestamp2.getHours()) * 3600 + (timestamp1.getMinutes() + timestamp2.getMinutes()) * 60 + (timestamp1.getSeconds() + timestamp2.getSeconds());

	return turnIntoTimestamp(allSeconds);
}
int main()
{
	Timestamp customTimestamp(5, 32, 58);

	customTimestamp.printTimestamp();

	Timestamp generatedTimestamp = turnIntoTimestamp(4000);

	generatedTimestamp.printTimestamp();
	cout << turnIntoSeconds(generatedTimestamp);

	Timestamp resultTimestamp = addTwoTimestamps(generatedTimestamp, customTimestamp);

	resultTimestamp.printTimestamp();
}

