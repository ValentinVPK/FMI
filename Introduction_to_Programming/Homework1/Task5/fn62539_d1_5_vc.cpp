/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Valentin Krumov
* @idnumber 62539
* @task 5
* @compiler VC
*
*/


#include <iostream>
using namespace std;

int main()
{
    int number;
    cin >> number;
    while (number < 2 || number > pow(10, 9)) {
        cin >> number;
    }

    bool isInfinite = false, isPrime = false;

    // Checking if the number is a prime number:
    if (number > 10 || number == 3 || number == 7) {
        isPrime = true;
        for (int i = 2; i < number; i++) {
            if (number % i == 0) {
                isPrime = false;
                break;
            }
        }
    }

    // Checking if 1/number is infinite:
    for (int i = 2; i < number; i++) {
        if (i % 2 == 0 || i % 5 == 0) continue;
        else if (number % i == 0) {
            isInfinite = true;
            break;
        }
    }

    //Printing the result;
    double result = 1.0 / number;

    if (isInfinite || isPrime) cout << "NO" << endl;
    else {
        int count = 0;
        while (result != (int)result) {
            count++;
            result = result * 10;
        }
        cout << count;
    }
    return 0;
}


