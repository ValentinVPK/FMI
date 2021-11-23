
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int num;
    cin >> num;

	vector<pair<pair<int, int>, int>> teamsWithIds;

	for (int i = 0; i < num; i++)
	{
		int goodTeam, enemyTeam;
		cin >> goodTeam >> enemyTeam;
		pair<pair<int, int>, int> currTeam;
		
		currTeam.first.first = goodTeam;
		currTeam.first.second = enemyTeam;
		currTeam.second = i + 1;

		teamsWithIds.push_back(currTeam);
	}

	std::sort(teamsWithIds.begin(), teamsWithIds.end(),
		[](pair<pair<int, int>, int> left, pair<pair<int, int>, int> right) {
			double leftPoints = (left.first.first * left.first.first) * 1.0 / left.first.second * 1.0;

			double rightPoints = (right.first.first * right.first.first) * 1.0 / right.first.second * 1.0;

			if (leftPoints != rightPoints) {
				return leftPoints < rightPoints;
			}

			return left.first.first < right.first.first;
		});

	for (int i = teamsWithIds.size() - 1; i >= 0; i--)
	{
		cout << teamsWithIds[i].second << " ";
	}

	return 0;
}


