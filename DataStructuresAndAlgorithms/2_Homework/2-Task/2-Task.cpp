
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    int num;
    cin >> num;

	vector<pair<vector<int>, int>> datesWithPlaces;

	int seconds, minutes, hours, day, month, year;
	char symbol;
	for (int i = 0; i < num; i++)
	{
		cin >> hours >> symbol >> minutes >> symbol >> seconds >> day >> symbol >> month >> symbol >> year;

		pair<vector<int>, int> currDate;
		currDate.first.push_back(year);
		currDate.first.push_back(month);
		currDate.first.push_back(day);
		currDate.first.push_back(hours);
		currDate.first.push_back(minutes);
		currDate.first.push_back(seconds);
		currDate.second = i + 1;

		datesWithPlaces.push_back(currDate);
	}

	std::sort(datesWithPlaces.begin(), datesWithPlaces.end(),
		[](pair<vector<int>, int> left, pair<vector<int>, int> right) {
			if (left.first[0] != right.first[0]) 
			{
				return left.first[0] < right.first[0];
			}

			if (left.first[1] != right.first[1])
			{
				return left.first[1] < right.first[1];
			}

			if (left.first[2] != right.first[2])
			{
				return left.first[2] < right.first[2];
			}

			if (left.first[3] != right.first[3])
			{
				return left.first[3] < right.first[3];
			}

			if (left.first[4] != right.first[4])
			{
				return left.first[4] < right.first[4];
			}

			if (left.first[5] != right.first[5])
			{
				return left.first[5] < right.first[5];
			}

			return left.second < right.second;
		});

	for (int i = 0; i < (int)datesWithPlaces.size(); i++)
	{
		cout << datesWithPlaces[i].second << endl;
	}

	return 0;
}

