
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
using namespace std;

class MyQueue
{
private:
	queue<int> mainQueue;
	deque<int> minQueue;

public:
	void clearQueue(deque<int>& dq)
	{
		while (dq.empty() == false)
		{
			dq.pop_front();
		}
	}

	int GetMinNumber()
	{
		return minQueue.front();
	}

	void myPush(int num)
	{
		mainQueue.push(num);

		if (minQueue.empty() == false && num < minQueue.front())
		{
			clearQueue(minQueue);
		}

		while (minQueue.empty() == false && num < minQueue.back())
		{
			minQueue.pop_back();
		}

		minQueue.push_back(num);
	}

	void myPop()
	{
		int num = mainQueue.front();
		mainQueue.pop();

		if (num == minQueue.front())
		{
			minQueue.pop_front();
		}
	}
};

int main()
{
	//10 4
	//1 3 9 5 2 7 4 11 5 6
    int N, d;

    cin >> N >> d;
	if (d == 0)
	{
		cout << 0;
		return 0;
	}

	MyQueue* minQueue = new MyQueue();
	long sum = 0;
	
	for (int i = 0; i < N; i++)
	{
		int currNum;
		cin >> currNum;

		if (i  <= d - 2)
		{
			minQueue->myPush(currNum);
			continue;
		}
		
		minQueue->myPush(currNum);

		sum += minQueue->GetMinNumber();

		minQueue->myPop();
	}

	cout << sum;
}


