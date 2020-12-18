
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

    // MainDiag

    bool isDownTriangleMainDiag = true;
    bool isUpTriangleMainDiag = true;
    for (size_t i = 0; i < K; ++i) {
        for (size_t j = 0; j < K; ++j) {
            if (j < i) {
                if (arr[i][j] != 0) isDownTriangleMainDiag = false;
            }
            if (j > i) {
                if (arr[i][j] != 0) isUpTriangleMainDiag = false;
            }
        }
    }

    // SecondDiag
    bool isDownTriangleSecondDiag = true;
    bool isUpTriangleSecondDiag = true;
    for (size_t i = 0; i < K; ++i) {
        for (size_t j = 0; j < K; ++j) {
            if (j > K - i - 1) {
                if (arr[i][j] != 0) isDownTriangleSecondDiag = false;
            }
            if (j < K - i - 1) {
                if (arr[i][j] != 0) isUpTriangleSecondDiag = false;
            }
        }
    }

    if (isDownTriangleMainDiag || isDownTriangleSecondDiag || isUpTriangleMainDiag || isUpTriangleSecondDiag) {
        cout << "yes";
    }
    else cout << "no";
}

