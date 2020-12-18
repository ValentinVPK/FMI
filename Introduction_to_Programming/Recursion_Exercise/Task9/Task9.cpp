
#include <iostream>
using namespace std;

unsigned DigitsAmount(unsigned number) {
    if (number == 0) return 0;

    number /= 10;

    return 1 + DigitsAmount(number);
}

int main()
{
    unsigned number;
    cin >> number;

    cout << DigitsAmount(number);
}


