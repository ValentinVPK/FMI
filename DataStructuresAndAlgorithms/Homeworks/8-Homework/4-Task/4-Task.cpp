
#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int clientsNumber, operatorsNumber;
    cin >> clientsNumber >> operatorsNumber;

	vector<pair<int, int>> clients;

	int timeOfCalling, duration;
	for (size_t i = 0; i < clientsNumber; i++)
	{
		cin >> timeOfCalling >> duration;
		clients.push_back({ timeOfCalling, duration });
	}

	vector<int> operatorsCounter;
	for (size_t i = 0; i < operatorsNumber; i++)
	{
		operatorsCounter.push_back(0);
	}

	set<int> operatorsAvailable;
	for (size_t i = 0; i < operatorsNumber; i++)
	{
		operatorsAvailable.insert(i);
	}

	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> calls;
	for (size_t i = 0; i < clientsNumber; i++)
	{
		int currTimeOfCalling = clients[i].first;

		while (!calls.empty() && calls.top().first <= currTimeOfCalling)
		{
			operatorsAvailable.insert(calls.top().second);
			calls.pop();
		}

		if (operatorsAvailable.empty())
		{
			continue;
		}

		auto operatorsIt = operatorsAvailable.lower_bound(i % operatorsNumber);

		if (operatorsIt == operatorsAvailable.end())
		{
			operatorsIt = operatorsAvailable.begin();
		}

		operatorsCounter[*operatorsIt]++;
		calls.push({ clients[i].first + clients[i].second,*operatorsIt });
		operatorsAvailable.erase(operatorsIt);
	}


	int maxCalls = operatorsCounter[0];

	for (size_t i = 0; i < operatorsNumber; i++)
	{
		if (operatorsCounter[i] > maxCalls)
		{
			maxCalls = operatorsCounter[i];
		}
	}

	vector<int> bestOperators;

	for (size_t i = 0; i < operatorsNumber; i++)
	{
		if (operatorsCounter[i] == maxCalls)
		{
			bestOperators.push_back(i);
		}
	}

	for (size_t i = 0; i < bestOperators.size(); i++)
	{
		cout << bestOperators[i] << " ";
	}

	return 0;
}

