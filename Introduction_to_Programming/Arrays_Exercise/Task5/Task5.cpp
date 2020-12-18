
#include <iostream>
using namespace std;

int main()
{
    int n;
    int arr[100];

    cin >> n;

    for (size_t i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 1;
    int maxCount = 0;

    for (size_t j = 0; j < n - 1; j++) {
        if (arr[j] < arr[j + 1]) count++;
        else {
            if (count > maxCount) maxCount = count;
            count = 1;
        }
    }

    cout << maxCount << endl;
}

