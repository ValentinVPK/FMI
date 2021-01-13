/**
*
* Solution to homework assignment 4
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


bool isInputValid(int den1, int den2, char sign) {
    if ((den1 < -100000000 || den1 > 100000000 || den1 == 0) || (den2 < -100000000 || den2 > 100000000 || den2 == 0)) {
        return false;
    }

    if (sign != '+' && sign != '-' && sign != '*' && sign != '/') {
        return false;
    }

    return true;
}

int findNOD(int a, int b) {
    if (a == 0) {
        return b;
    }

    return findNOD(b % a, a);
}

void simplestForm(int& num3, int& den3)
{
    int resultNOD = findNOD(num3, den3);

    num3 = num3 / resultNOD;
    den3 = den3 / resultNOD;
}


int* fractionOperations(int num1, int den1, int num2, int den2, char sign) {
    int* result = new int[2];
    int num3, den3;

    switch (sign) {
        case '+':
            den3 = (den1 * den2) / findNOD(den1, den2);
            num3 = (num1) * (den3 / den1) + (num2) * (den3 / den2);

            simplestForm(num3, den3);

            result[0] = num3;
            result[1] = den3;
            break;
        case '-':
            den3 = (den1 * den2) / findNOD(den1, den2);
            num3 = (num1) * (den3 / den1) - (num2) * (den3 / den2);

            simplestForm(num3, den3);

            result[0] = num3;
            result[1] = den3;
            break;
        case '*':
            num3 = num1 * num2;
            den3 = den1 * den2;

            simplestForm(num3, den3);

            result[0] = num3;
            result[1] = den3;
            break;
        case '/':
            num3 = num1 * den2;
            den3 = den1 * num2;

            simplestForm(num3, den3);

            result[0] = num3;
            result[1] = den3;
            break;
    }

    return result;
}

int main()
{
    int num1, den1, num2, den2; // den = denomanitor;
    char sign;

    cin >> num1 >> den1;
    cin >> sign;
    cin >> num2 >> den2;

    if (!isInputValid(den1, den2, sign)) {
        cout << -1;
        return 0;
    }

    int* result = fractionOperations(num1, den1, num2, den2, sign);

    for (int i = 0; i < 2; i++) {
        cout << result[i] << " ";
    }

    delete[] result;

    return 0;
}


