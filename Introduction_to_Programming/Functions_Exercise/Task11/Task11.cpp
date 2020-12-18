
#include <iostream>
using namespace std;

void EqualDigits(const int start, const int end) {
    for (int i = start; i <= end; i++) {
        int lastDigit = i % 10;
        bool areDigitsEqual = true;
        while (i > 0) {
            if (i % 10 != lastDigit) {
                areDigitsEqual = false;
                break;
            }
            else i = i / 10;
        }

        if (areDigitsEqual) cout << i << " ";
    }
}
int main()
{
    int start, end;
    cin >> start >> end;

    EqualDigits(start, end);
}

