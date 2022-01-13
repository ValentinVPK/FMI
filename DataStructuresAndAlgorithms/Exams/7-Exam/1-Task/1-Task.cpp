
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>
using namespace std;

int main()
{
    int N;
    cin >> N;

	map<int, int> numbersCount;
	queue<int> q;

	int currNumber;
	for (size_t i = 0; i < N; i++)
	{
		cin >> currNumber;
		numbersCount[currNumber]++;

		if (numbersCount[currNumber] == 1)
		{
			q.push(currNumber);
		}
	}


	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		if (numbersCount[curr] > 1)
		{
			q.push(curr);
			numbersCount[curr] = 1;
		}
		else if (numbersCount[curr] == 1)
		{
			cout << curr << " ";
		}
	}
}

