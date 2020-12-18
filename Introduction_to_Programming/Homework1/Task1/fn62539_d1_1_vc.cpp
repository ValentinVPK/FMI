/**
*
* Solution to homework assignment 1
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
using namespace std;

int main()
{
    int birthday, laptopPrice, toyPrice, earnedMoney = 0, evenBirthdayMoney = 30;
    cin >> birthday;
    while (birthday <= 0) {
        cin >> birthday;
    }
    cin >> laptopPrice;
    while (laptopPrice < 0) {
        cin >> laptopPrice;
    }
    cin >> toyPrice;
    while (toyPrice < 0) {
        cin >> toyPrice;
    }

    for (int i = 1; i <= birthday; i++) {
        if (i % 2 == 0) {
            earnedMoney = earnedMoney + evenBirthdayMoney - 5;
            evenBirthdayMoney += 30;
        }
        else {
            earnedMoney += toyPrice;
        }
    }

    if (earnedMoney >= laptopPrice) {
        cout << "yes" << endl << earnedMoney - laptopPrice;
    }
    else {
        cout << "no" << endl << laptopPrice - earnedMoney;
    }

    return 0;
}


