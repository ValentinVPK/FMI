/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Valentin Krumov
* @idnumber 62539
* @task 2
* @compiler VC
*
*/


#include <iostream>
using namespace std;

int main()
{
    int number, biggestNumber = 0, secondBiggestNumber = 0;
    cin >> number;
    while (number > 0) {
        if (number > biggestNumber) {
            secondBiggestNumber = biggestNumber;
            biggestNumber = number;
        }
        else if (number > secondBiggestNumber) {
            secondBiggestNumber = number;
        }

        cin >> number;
    }
    if (secondBiggestNumber == 0 || secondBiggestNumber == biggestNumber) {
        cout << -1;
    }
    else {
        cout << secondBiggestNumber;
    }
    return 0;
}


