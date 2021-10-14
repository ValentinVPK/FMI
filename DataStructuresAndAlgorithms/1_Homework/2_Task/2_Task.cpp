#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    unsigned n;
    int number;

    cin >> n;

    vector<unsigned> allNumbers;

    for (size_t i = 0; i < n; i++)
    {
        cin >> number;
        if (number < 0) {
            continue;
        }

        allNumbers.push_back(number);
    }

    sort(allNumbers.begin(), allNumbers.end());

    unsigned missingNumber = 1;

    for (size_t i = 0; i < allNumbers.size(); i++)
    {
        if (i == allNumbers.size() - 1) {
            if (missingNumber == allNumbers[i]) {
                missingNumber++;
            }
        }
        else if (missingNumber == allNumbers[i] && missingNumber != allNumbers[i + 1]) {
            missingNumber++;
        }
    }

    cout << missingNumber;

    return 0;
}
