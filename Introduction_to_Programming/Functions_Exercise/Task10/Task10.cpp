
#include <iostream>
using namespace std;

double Average(const int N) {
    int sum = 0;
    int number;
    for (int i = 0; i < N; i++) {
        cin >> number;
        sum += number;
    }

    return (double)sum / N;
}
int main()
{
    int N;
    cin >> N;

    cout << Average(N);
}

