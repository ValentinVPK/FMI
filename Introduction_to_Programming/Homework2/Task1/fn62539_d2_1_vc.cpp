/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Valentin Krumov
* @idnumber 62539
* @task 1
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
    while (vectorSize < 3 || vectorSize > 100) {
        cin >> vectorSize;
    }
    vector<int> numbers(vectorSize);

    for (size_t i = 0; i < vectorSize; i++) {
        cin >> numbers[i];
        while (numbers[i] < 1) {
            cin >> numbers[i];
        }
    }

    bool isTriangular = true;
    int lastIndex = vectorSize - 1;
    for (size_t i = 0; i < vectorSize / 2; i++) {
        int leftSubstraction = abs(numbers[i] - numbers[i + 1]);
        int rightSubstraction = abs(numbers[lastIndex] - numbers[lastIndex - 1]);
        if (leftSubstraction != rightSubstraction) {
            isTriangular = false;
            break;
        }
        lastIndex--;
    }

    if (isTriangular) cout << 1;
    else cout << 0;

    return 0;
}

