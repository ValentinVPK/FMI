
#include <iostream>
using namespace std;

double Calculate(const int num1, const int num2, char action) {
    switch (action) {
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return (num1 * 1.0) / num2;
        case '%':
            return num1 % num2;
        default:
            return num1 + num2;
    }
}
int main()
{
    int num1, num2;
    char action;
    cin >> num1 >> num2 >> action;

    cout << Calculate(num1, num2, action);
}

