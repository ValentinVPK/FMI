
#include <iostream>
using namespace std;

bool DoesNumberContainK(unsigned number, unsigned K) {
    if (number == 0) return K == 0;

    unsigned lastDigit = number % 10;
    number /= 10;

    return lastDigit == K || DoesNumberContainK(number, K);
}
int main()
{
    unsigned number, K;
    cin >> number >> K;

    cout << DoesNumberContainK(number, K);
}

