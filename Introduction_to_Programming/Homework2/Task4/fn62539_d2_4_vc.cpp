/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Valentin Krumov
* @idnumber 62539
* @task 4
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
    while (vectorSize < 3 || vectorSize > 100) cin >> vectorSize;

    vector<int> numbers;
    int number;
    for (size_t i = 0;i < vectorSize; i++) {
        bool doesNumberExist = false;
        cin >> number;

        for (size_t j = 0; j < numbers.size(); j++) {
            if (numbers[j] == number) {
                i--;
                doesNumberExist = true;
                break;
            }
        }
        if(!doesNumberExist) numbers.push_back(number);
    }

    int zeroSumsCount = 0;
    for (size_t i = 0;i < vectorSize; i++) {
        for (size_t j = i + 1; j < vectorSize; j++) {
            for (size_t t = j + 1; t < vectorSize; t++) {
                if ((numbers[i] + numbers[j] + numbers[t]) == 0) zeroSumsCount++;
            }
        }
    }
    cout << zeroSumsCount;

    return 0;
}


