
#include <iostream>
using namespace std;

bool IsEven(const int num) {
    if (num % 2 == 0) return true;
    else return false;
}
int main()
{
    int num;
    cin >> num;
    cout << IsEven(num);
}


