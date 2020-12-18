
#include <iostream>
using namespace std;

int main()
{
    int K;

    cin >> K;

    double arr[100][100];
    for (size_t i = 0; i < K; ++i) {
        for (size_t j = 0; j < K; ++j) {
            cin >> arr[i][j];
        }
    }

    double sum = 0;
    for (size_t i = 0; i < K; ++i) {
        for (size_t j = 0; j < K; j++) {
            if (j <= i) {
                sum += arr[i][j];
            }
        }
    }
    cout << sum;
    cout << endl;
    return 0;
}

