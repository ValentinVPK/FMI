
#include <iostream>
using namespace std;

int Pow(const int num, const unsigned N) {
    double result = 1;
    for (int i = 0; i < N; i++) {
        result *= num;
    }

    return result;
}
int main()
{
    int num;
    unsigned N;
    cin >> num >> N;

    cout << Pow(num, N);
}

