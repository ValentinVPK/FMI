
#include <iostream>

using namespace std;

int main()
{
    char arr[100];
    int result = 0, n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (size_t i = 0; i < n; i++) {
        result = result + arr[i];
    }

    cout << result;
}

