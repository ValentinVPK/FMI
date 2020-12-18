
#include <iostream>
using namespace std;

unsigned DigitsSum(unsigned number) {
    if (number <= 0) return 0;

    unsigned lastDigit = number % 10;
    number /= 10;

    return lastDigit + DigitsSum(number);
}

bool IsSumEqualTo5(int sum) {
    if (sum == 5) return true;

    return false;
}
int main()
{
    unsigned number;
    cin >> number;

    cout << IsSumEqualTo5(DigitsSum(number));
}

