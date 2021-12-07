
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main()
{
    int N;
    cin >> N;

    map<int,int> numbersCount;

    int currNumber;
    for (size_t i = 0; i < N; i++)
    {
        cin >> currNumber;

        if (!numbersCount.count(currNumber))
        {
            numbersCount[currNumber] = 1;
        }
        else
        {
            numbersCount[currNumber]++;
        }
    }


    int resultSum = 0;

    for (auto number : numbersCount)
    {
        if (number.second % 2 != 0)
        {
            resultSum += number.first * number.second;
        }
    }

    cout << resultSum;

    return 0;
}

