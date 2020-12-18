
#include <iostream>
using namespace std;

bool IsEqual(int number) {
    if (number < 10) {
        return false;
    }

    int firstTwoDigitsNumber, digitsSum = 0;
    
    while (number > 0) {
        if (number >= 10 && number < 100) {
            firstTwoDigitsNumber = number;
        }
        digitsSum += number % 10;
        number /= 10;
    }

    return firstTwoDigitsNumber == digitsSum;
}
int main()
{
    int number;
    cin >> number;

    if (IsEqual(number)) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}

