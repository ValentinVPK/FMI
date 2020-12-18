
#include <iostream>
using namespace std;

int main()
{
    char arr[100];
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) swap(arr[i], arr[j]);
            for (size_t i = 0; i < n; i++) {
                cout << arr[i];
            }
            cout << endl;
        }
    }
}

