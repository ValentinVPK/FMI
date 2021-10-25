#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int binarySearch(vector<long>& vec, long number) {
    long l = 0;
    long r = vec.size() - 1;

    while (true)
    {
        if (l > r)
        {
            int wantedIndex = r + 1;
            if (wantedIndex == 0)
            {
                return wantedIndex;
            }

            if (wantedIndex == vec.size())
            {
                return wantedIndex - 1;
            }


            long rightDiff = abs(number - vec[wantedIndex]);
            long leftDiff = abs(number - vec[wantedIndex - 1]);

            if (leftDiff <= rightDiff)
            {
                return wantedIndex - 1;
            }
            else if (rightDiff < leftDiff)
            {
                return wantedIndex;
            }
        }

        long mid = (l + r) / 2;

        if (vec[mid] == number) {
            return mid;
        }

        if (vec[mid] < number) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
}
int main()
{
    int teamsNumber, subjectsNumber;

    cin >> subjectsNumber >> teamsNumber;

    vector<long> teamsSkiils;
    vector<long> subjectsDifficulty;

    for (int i = 0; i < subjectsNumber; i++)
    {
        long currSubject;
        cin >> currSubject;

        subjectsDifficulty.push_back(currSubject);
    }

    for (int i = 0; i < teamsNumber; i++)
    {
        long currTeam;
        cin >> currTeam;

        teamsSkiils.push_back(currTeam);
    }

    sort(subjectsDifficulty.begin(), subjectsDifficulty.end());

    for (int i = 0; i < teamsNumber; i++)
    {
        cout << subjectsDifficulty[binarySearch(subjectsDifficulty, teamsSkiils[i])] << endl;
    }

    return 0;
}


