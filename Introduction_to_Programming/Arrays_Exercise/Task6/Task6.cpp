
#include <iostream>
using namespace std;

int main()
{
    int arrM[100], arrN[100];
    int n, m;

    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> arrN[i];
    }

    cin >> m;

    for (size_t i = 0; i < m; i++) {
        cin >> arrM[i];
    }

    int indexM = 0;
    for (size_t i = n; i < n + m; i++) {
        arrN[i] = arrM[indexM];
        indexM++;
    }

    for (size_t i = 0; i < n + m; i++) {
        cout << arrN[i] << " ";
    }
}

