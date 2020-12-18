/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Valentin Krumov
* @idnumber 62539
* @task 3
* @compiler VC
*
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int vectorSize;
    cin >> vectorSize;
    while (vectorSize < 3 || vectorSize > 1000) cin >> vectorSize;

    vector<double> digits(vectorSize);

    for (size_t i = 0; i < vectorSize; i++) {
        cin >> digits[i];
        while (digits[i] < 0 || digits[i] > 9) cin >> digits[i];
    }

    int palindromesCount = 0;
    vector<int> subVector;
    vector<int> subVectorReversed;
    for (size_t i = 0; i < vectorSize; i++) {
        for (int j = i + 2; j < vectorSize; j++) {
            for (size_t t = i; t <= j; t++) {
                subVector.push_back(digits[t]);
            }
            subVectorReversed = subVector;
            for (size_t s = 0, k = subVectorReversed.size() - 1; s < subVectorReversed.size() / 2; s++, k--)
            {
                int temp = subVectorReversed[s];
                subVectorReversed[s] = subVectorReversed[k];
                subVectorReversed[k] = temp;
            }
            if (subVector == subVectorReversed) {
                palindromesCount++;
            }
            subVector.clear();
            subVectorReversed.clear();
        }
    }

    if (palindromesCount == 0) cout << -1;
    else cout << palindromesCount;

    return 0;
}


