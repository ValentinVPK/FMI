
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

    bool containsDifferentElements = true;

    for (size_t i = 0; i < n ; i++) {
        for (size_t j = 0; j < n; j++) {
            if (j == i) continue;

            if (arr[j] == arr[i]) containsDifferentElements = false;
        }
    }

    if (containsDifferentElements) cout << "yes" << endl;
    else cout << "no" << endl;
}

