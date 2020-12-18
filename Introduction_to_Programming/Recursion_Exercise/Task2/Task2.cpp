
#include <iostream>
using namespace std;

int Sum(int N) {
    if (N == 0) return 0;

    return N + Sum(N - 1);
}



int main()
{
    int N;
    cin >> N;

    cout << Sum(N);
}


