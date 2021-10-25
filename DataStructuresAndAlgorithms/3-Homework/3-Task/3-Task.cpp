
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binaryFindIndex(vector<int>& vec, int left, int right, int number)
{
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (vec[mid] >= number)
            right = mid;
        else
            left = mid;
    }

    return right;
}

int lisLength(vector<int>& vec)
{
    if (vec.size() == 0)
        return 0;

    vector<int> temp(vec.size(), 0);
    int result = 1; 

    temp[0] = vec[0];
    for (int i = 1; i < (int)vec.size(); i++) 
    {
        if (vec[i] < temp[0])
            temp[0] = vec[i];
        else if (vec[i] > temp[result - 1])
            temp[result++] = vec[i];
        else
            temp[binaryFindIndex(temp, -1, result - 1, vec[i])] = vec[i];
    }

    return result;
}

int main()
{
    int number;
    cin >> number;

    vector<pair<int, int>> demons;

    pair<int, int> hero;

    for (int i = 0; i < number; i++)
    {
        int defense, attack;
        cin >> defense >> attack;

        pair<int, int> currStats;
        currStats.first = defense;
        currStats.second = attack;

        demons.push_back(currStats);
    }

    std::sort(demons.begin(), demons.end());
        

    vector<int> allDefences;
    vector<int> allAttacks;

    for (int i = 0; i < (int)demons.size(); i++)
    {
        allDefences.push_back(demons[i].first);
        allAttacks.push_back(demons[i].second);
    }

    int deffLIS = lisLength(allDefences);
    int attackLIS = lisLength(allAttacks);

    if (deffLIS <= attackLIS)
    {
        cout << deffLIS;
    }
    else
    {
        cout << attackLIS;
    }

    return 0;
}

