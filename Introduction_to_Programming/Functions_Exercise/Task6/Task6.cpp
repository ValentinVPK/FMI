
#include <iostream>
using namespace std;

int Ascii(const char symbol) {
    return symbol;
}
int main()
{
    char symbol;
    cin >> symbol;

    cout << Ascii(symbol);
}

