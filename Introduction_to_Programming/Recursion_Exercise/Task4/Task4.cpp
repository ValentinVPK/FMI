
#include <iostream>
using namespace std;

int Pow(int x, int n) {
    if (n == 1) return x;

    return x * Pow(x, n-1);
}

int main()
{
    int x, n;
    cin >> x >> n;

    cout << Pow(x, n);
}

