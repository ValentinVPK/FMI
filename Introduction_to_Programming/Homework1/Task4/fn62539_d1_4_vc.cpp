/**
*
* Solution to homework assignment 1
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
using namespace std;

int main()
{
    int number, minSumDivisor1 = 1, minSumDivisor2 = 1, minSumDivisor3 = 1;
    cin >> number;
    while (number < 1 || number > pow(10, 9)) {
        cin >> number;
    }
    int minSum = number + 3;

    for (int firstDivisor = 1; firstDivisor <= number; firstDivisor++) {
        for (int secondDivisor = 1; secondDivisor <= number; secondDivisor++) {
            for (int thirdDivisor = 1; thirdDivisor <= number; thirdDivisor++) {
                if ((firstDivisor * secondDivisor * thirdDivisor) == number && (firstDivisor + secondDivisor + thirdDivisor) < minSum) {
                    minSumDivisor1 = firstDivisor;
                    minSumDivisor2 = secondDivisor;
                    minSumDivisor3 = thirdDivisor;
                    minSum = firstDivisor + secondDivisor + thirdDivisor;
                }
            }
        }
    }

    cout << minSumDivisor1 << " " << minSumDivisor2 << " " << minSumDivisor3;

    return 0;
}


