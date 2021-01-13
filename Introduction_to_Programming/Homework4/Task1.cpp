/**
*
* Solution to homework assignment 4
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

bool areChangesEnough(int arr[], int size, int changesAmount)
{
    int maxLIS = 0;
    int * LIS = new int[size]; // LIS = Longest Increasing Subsequence

    for (int i = 0; i < size; i++) {
        LIS[i] = 1;
    }

    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] >= arr[j] && LIS[i] < LIS[j] + 1) {
                LIS[i] = LIS[j] + 1;
            }
        }
    }
    

    for (int i = 0; i < size; i++) {
        if (maxLIS < LIS[i]) {
            maxLIS = LIS[i];
        }
    }

    delete[] LIS;

    return (size - maxLIS) <= changesAmount;
}

int main()
{
    int changesAmount, size;
    
    cin >> changesAmount;
    cin >> size;
    
    int* arr = new int[size];

    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
        if (arr[i] <= 0) {
            cout << -1;
            return 0;
        }
    }

    cout << areChangesEnough(arr, size, changesAmount);

    delete[] arr;

    return 0;
}


