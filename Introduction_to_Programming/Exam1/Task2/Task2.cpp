
#include <iostream>
using namespace std;

int SumOfDigits(int numbers[], int N, int i = 0) {
    if (i == N) return 0;
    int digitsSum = 0;

    while (numbers[i] > 0) {
        digitsSum += numbers[i] % 10;
        numbers[i] /= 10;
    }

    return digitsSum + SumOfDigits(numbers, N, i + 1);
}
int main()
{
    int numbers[100];
    int N;
    cin >> N;

    for (size_t i = 0; i < N; i++) {
        cin >> numbers[i];
        if (numbers[i] < 0) {
            numbers[i] *= -1;
        }
    }
    
    cout << SumOfDigits(numbers, N) << endl;

    return 0;
}

