
#include <iostream>
using namespace std;

int Trunc(double num) {
    if (num < 0) return (int)num;
    else return (int)num;
}
int main()
{
    double num;
    cin >> num;

    cout << Trunc(num);
}

