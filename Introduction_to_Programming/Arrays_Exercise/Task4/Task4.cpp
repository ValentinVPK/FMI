
#include <iostream>

using namespace std;

int main()
{
    int arr[100];
    int n;

    cin >> n;

    for (size_t i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool isIncreasing = true;
    bool isDecreasing = true;

    for (size_t j = 0; j < n - 1; j++) {
        if (arr[j] >= arr[j + 1]) isIncreasing = false;

        if (arr[j] <= arr[j + 1]) isDecreasing = false;
    }

    if (isIncreasing) cout << "Arr is increasing" << endl;
    else if (isDecreasing) cout << "Arr is decreasing" << endl;
    else cout << "Arr is neither increasing , nor decreasing" << endl;
}


