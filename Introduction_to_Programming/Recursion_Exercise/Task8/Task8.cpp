
#include <iostream>
using namespace std;

unsigned DigitsMultiplication(unsigned number) {
    if (number <= 0) return 1;

    unsigned lastDigit = number % 10;
    number /= 10;

    return lastDigit * DigitsMultiplication(number);
}
int main()
{
    unsigned number;
    cin >> number;
    
    cout << DigitsMultiplication(number);
}

