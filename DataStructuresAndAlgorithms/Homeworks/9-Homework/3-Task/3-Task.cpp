#include <iostream>
#include <string>
#include <vector>
using namespace std;
int findLength(string str1, string str2 , int size1, int size2) {
    int** matrix = new int* [size1 + 1];

    for (size_t i = 0; i < size1 + 1; i++)
    {
        matrix[i] = new int[size2 + 1];
    }

    int row, col;
    int strLen = 0;
    for (size_t i = 0; i <= size1; i++) 
    {
        for (size_t j = 0; j <= size2; j++)
        {
            if (i == 0 || j == 0)
            {
                matrix[i][j] = 0;
            } 
            else if (str1[i - 1] == str2[j - 1]) 
            {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
                if (matrix[i][j] > strLen)
                {
                    strLen = matrix[i][j];
                    row = i;
                    col = j;
                }
            }
            else
            {
                matrix[i][j] = 0;
            }
        }
    }
    return strLen;
}
int main() {
    string str1;
    string str2;

    cin >> str1 >> str2;
    cout << findLength(str1, str2, str1.size(), str2.size());
    return 0;
}