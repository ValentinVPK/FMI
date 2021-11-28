

#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    set<int> setOfNumbers;
    setOfNumbers.insert(0);

    int querries;
    cin >> querries;

    int currNum;
    int minElement = INT_MAX;
    for (size_t i = 1; i <= querries; i++)
    {
        cin >> currNum;
        setOfNumbers.insert(currNum);

        auto it = setOfNumbers.find(currNum);

        auto leftIt = it;
        leftIt--;

        auto rightIt = it;
        rightIt++;

        int leftXOR = (*leftIt) ^ currNum;

        if (leftXOR < minElement)
        {
            minElement = leftXOR;
        }

        if (rightIt != setOfNumbers.end())
        {
            int rightXOR = (*rightIt) ^ currNum;
            if (rightXOR < minElement)
            {
                minElement = rightXOR;
            }
        }

        printf("%d\n", minElement);
    }

    return 0;
}


