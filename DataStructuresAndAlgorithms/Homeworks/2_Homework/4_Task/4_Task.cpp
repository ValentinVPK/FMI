#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int num;
	cin >> num;
    vector<pair<pair<double, double>, int>> vec;

	for (int i = 0; i < num; i++)
	{
		double di, ti;
		cin >> di >> ti;

		pair<pair<double, double>,int> currBoyParams;
		currBoyParams.first.first = di;
		currBoyParams.first.second = ti;

		currBoyParams.second = i + 1;

		vec.push_back(currBoyParams);
	}

	std::sort(vec.begin(), vec.end(),
		[](pair<pair<double, double>, int> left,
			pair<pair<double, double>, int> right) {
				double leftRadius = left.first.first / 2;
				double leftTime = left.first.second;
				double leftEfficiency =
					(leftRadius * leftRadius) / leftTime;

				double rightRadius = right.first.first / 2;
				double rightTime = right.first.second;
				double rightEfficiency =
					(rightRadius * rightRadius) / rightTime;
				if (leftEfficiency == rightEfficiency) 
				{
					return left.first.first > right.first.first;
				}

				return leftEfficiency > rightEfficiency;
		});

	for (int i = 0; i < (int)vec.size(); i++)
	{
		cout << vec[i].second << " ";
	}

	return 0;
}

