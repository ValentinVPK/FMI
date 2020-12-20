
#include <iostream>
#include <vector>
using namespace std;

bool isMagicSquare(double** matrix,int size) {
    int primeDiagonalSum = 0, secondDiagonalSum = 0;
    // Prime Diagonal
    for (size_t i = 0; i < size; i++) {
        primeDiagonalSum += matrix[i][i];
    }

    // Secondary Diagonal

    for (size_t i = 0; i < size; i++) {
        secondDiagonalSum += matrix[i][size - i - 1];
    }

    if (primeDiagonalSum != secondDiagonalSum) return false;

    // Row sums
    for (size_t i = 0; i < size; i++) {
        int rowSum = 0;
        for (size_t j = 0; j < size; j++) {
            rowSum += matrix[i][j];
        }

        if (rowSum != primeDiagonalSum) return false;
    }

    // Col sums

    for (size_t i = 0; i < size; i++) {
        int colSum = 0;
        for (size_t j = 0; j < size; j++) {
            colSum += matrix[j][i];
        }

        if (colSum != primeDiagonalSum) return false;
    }

    return true;

}
int main()
{
    int size;
    cin >> size;
    while (size < 1 || size > 999) {
        cin >> size;
    }

    double** matrix = new double* [size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new double[size];
    }

    for (size_t i = 0;i < size;i++) {
        for (size_t j = 0;j < size;j++) {
            cin >> matrix[i][j];
            while (matrix[i][j] < 0 || matrix[i][j] > 100) {
                cin >> matrix[i][j];
            }
        }
    }

    if (isMagicSquare(matrix, size)) cout << "true" << endl;
    else cout << "false" << endl;

    for (size_t i = 0; i < size;++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

