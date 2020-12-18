
#include <iostream>
using namespace std;

int Abs(const int num) {
    if (num < 0) return -num;
    else return num;
}
int main()
{
    int num;
    cin >> num;

    cout << Abs(num);
}


