
#include <iostream>

using namespace std;

int main()
{
    int minNumber, maxNumber;
    int sum = 0, multiplication = 1;

    int n;
    int arr[100];

    for (size_t i = 0; i < n; i++) {
        cin >> arr[i];
    }

    minNumber = arr[0];
    maxNumber = arr[0];
    for (size_t i = 0; i < n; i++) {
        if (arr[i] < minNumber) minNumber = arr[i];
        if (arr[i] > maxNumber) maxNumber = arr[i];

        sum += arr[i];
        multiplication *= arr[i];
    }

    double median = 0;
    if (n % 2 == 0) median = (arr[n / 2] + arr[n / 2 - 1]) / 2.0;
    else median = arr[n / 2];

    cout << maxNumber << " " << minNumber << " " << sum << " " << multiplication << " " << median << endl;
}
