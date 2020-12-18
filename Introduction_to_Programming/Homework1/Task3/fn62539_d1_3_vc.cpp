/**
*
* Solution to homework assignment 1
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
using namespace std;

int main()
{
    short firstDigit, secondDigit, thirdDigit;
    cin >> firstDigit;
    while (firstDigit < 0 || firstDigit > 9) {
        cin >> firstDigit;
    }
    cin >> secondDigit;
    while (secondDigit < 0 || secondDigit > 9) {
        cin >> secondDigit;
    }
    cin >> thirdDigit;
    while (thirdDigit < 0 || thirdDigit > 9) {
        cin >> thirdDigit;
    }

    
    if (firstDigit == secondDigit && secondDigit == thirdDigit) {
        if (firstDigit == 0) cout << firstDigit;
        else cout << firstDigit << secondDigit << thirdDigit;
    }
    else if (firstDigit == secondDigit) {
        if (firstDigit == 0) cout << thirdDigit;
        else cout << firstDigit << thirdDigit << firstDigit;
    }
    else if (firstDigit == thirdDigit) {
        if (firstDigit == 0) cout << secondDigit;
        else cout << firstDigit << secondDigit << firstDigit;
    }
    else if (secondDigit == thirdDigit) {
        if (secondDigit == 0) cout << firstDigit;
        else cout << secondDigit << firstDigit << secondDigit;
    }
    else if (firstDigit < secondDigit && firstDigit < thirdDigit) {
        if (firstDigit == 0) {
            if (secondDigit < thirdDigit) cout << secondDigit << firstDigit << thirdDigit << firstDigit << secondDigit;
            else if (secondDigit > thirdDigit) cout << thirdDigit << firstDigit << secondDigit << firstDigit << thirdDigit;
        }
        else if (secondDigit < thirdDigit) cout << firstDigit << secondDigit << thirdDigit << secondDigit << firstDigit;
        else cout << firstDigit << thirdDigit << secondDigit << thirdDigit << firstDigit;
    }
    else if (secondDigit < firstDigit && secondDigit < thirdDigit) {
        if (secondDigit == 0) {
            if (firstDigit < thirdDigit) cout << firstDigit << secondDigit << thirdDigit << secondDigit << firstDigit;
            else if (firstDigit > thirdDigit) cout << thirdDigit << secondDigit << firstDigit << secondDigit << thirdDigit;
        }
        else if (firstDigit < thirdDigit) cout << secondDigit << firstDigit << thirdDigit << firstDigit << secondDigit;
        else cout << secondDigit << thirdDigit << firstDigit << thirdDigit << secondDigit;
    }
    else if (thirdDigit < firstDigit && thirdDigit < secondDigit) {
        if (thirdDigit == 0) {
            if (firstDigit < secondDigit) cout << firstDigit << thirdDigit << secondDigit << thirdDigit << firstDigit;
            else if (firstDigit > secondDigit) cout << secondDigit << thirdDigit << firstDigit << thirdDigit << secondDigit;
        }
        else if (firstDigit < secondDigit) cout << thirdDigit << firstDigit << secondDigit << firstDigit << thirdDigit;
        else cout << thirdDigit << secondDigit << firstDigit << secondDigit << thirdDigit;
    }

    return 0;
}

