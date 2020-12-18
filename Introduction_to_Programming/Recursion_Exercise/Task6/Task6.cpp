
#include <iostream>
using namespace std;

void ReverseNumber(int number) {
    if (number > 0) {
        int lastDigit = number % 10;
        number /= 10;
        cout << lastDigit;
        ReverseNumber(number);
    }
}
int main()
{
    int number;
    cin >> number;

    ReverseNumber(number);
}

