/**
*
* Solution to homework assignment 2
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
#include <vector>
using namespace std;

int main()
{
    int numberOfDays;
    cin >> numberOfDays;
    while (numberOfDays < 3 || numberOfDays > 365) cin >> numberOfDays;

    vector<double> stockPrices(numberOfDays);

    for (size_t i = 0; i < numberOfDays; i++) {
        cin >> stockPrices[i];
        while (stockPrices[i] < 0.1 || stockPrices[i] > 100) cin >> stockPrices[i];
    }

    int profit = 0;
    size_t i = 0;
    while(i < numberOfDays - 1) {
        int boughtStockIndex, soldStockIndex;
        while ((i < numberOfDays - 1) && (stockPrices[i + 1] <= stockPrices[i])) {
            i++;
        }

        if (i == numberOfDays - 1) {
            break;
        }

        boughtStockIndex = i;
        i++;

        while ((i < numberOfDays) && (stockPrices[i] >= stockPrices[i - 1])) {
            i++;
        }

        soldStockIndex = i - 1;
        profit += stockPrices[soldStockIndex] - stockPrices[boughtStockIndex];
    }
    cout << profit;

    return 0;
}


