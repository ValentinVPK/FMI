
#include <iostream>
using namespace std;

int main()
{
    int arr[100];
    int n, m, count = 0;

    cin >> n;
    cin >> m;

    for (size_t i = 0; i < n; i++) cin >> arr[i];

    for (size_t j = 0; j < n; j++) {
        if (arr[j] == m) count++;
    }
    cout << count << endl;
}


