﻿
#include <iostream>
using namespace std;

int main()
{
    int rows, cols;
    cin >> rows >> cols;
    int arr[100][100];

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    bool doesContainX = false;
    int x;
    cin >> x;
    for (size_t i = 0; i < rows; i++) {
        int sum = 0;
        for (size_t j = 0; j < cols; j++) {
            if (arr[i][j] == x) doesContainX = true;
        }
    }

    if (doesContainX) cout << "yes" << endl;
    else cout << "no" << endl;
}



