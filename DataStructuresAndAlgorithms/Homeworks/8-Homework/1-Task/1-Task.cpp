#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << std::setprecision(1) << std::fixed;

    int N;
    cin >> N;

	int currNum;
	double currMedian;
	vector<double> resultMedians;

	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for (int i = 0; i < N; i++)
	{
		cin >> currNum;

		if (i == 0)
		{
			currMedian = currNum;
			resultMedians.push_back(currMedian);
			maxHeap.push(currNum);
			continue;
		}

		if (currNum > currMedian)
		{
			if (maxHeap.size() == minHeap.size())
			{
				minHeap.push(currNum);
				currMedian = (minHeap.top() * 1.0);
			}
			else
			{
				if (maxHeap.size() < minHeap.size())
				{
					double currELement = minHeap.top();
					minHeap.pop();
					maxHeap.push(currELement);

					minHeap.push(currNum);
				}
				else if(maxHeap.size() > minHeap.size())
				{
					minHeap.push(currNum);
				}

				currMedian = (minHeap.top() + maxHeap.top()) / 2.0;
			}
		}
		else
		{
			if (maxHeap.size() == minHeap.size())
			{
				maxHeap.push(currNum);
				currMedian = (maxHeap.top() * 1.0);
			}
			else
			{
				if (maxHeap.size() < minHeap.size())
				{
					maxHeap.push(currNum);
				}
				else if (maxHeap.size() > minHeap.size())
				{
					double currELement = maxHeap.top();
					maxHeap.pop();
					minHeap.push(currELement);

					maxHeap.push(currNum);
				}

				currMedian = (minHeap.top() + maxHeap.top()) / 2.0;
			}
		}

		resultMedians.push_back(currMedian);
	}

	for (size_t i = 0; i < resultMedians.size(); i++)
	{
		printf("%.1f\n", resultMedians[i]);
	}

	return 0;
}

