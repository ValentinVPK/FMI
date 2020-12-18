
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

    bool isSymetric = true;
    for (size_t i = 0; i < K; ++i) {
        for (size_t j = 0; j < K; ++j) {
            if (i != j) {
                if (arr[i][j] != arr[j][i]) isSymetric = false;
            }
        }
    }

    if (isSymetric) cout << "yes";
    else cout << "no";
}

