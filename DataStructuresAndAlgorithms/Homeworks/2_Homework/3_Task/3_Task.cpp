
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<char> symbols;

    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        char symbol;
        cin >> symbol;
        symbols.push_back(symbol);
    }

    std::sort(symbols.begin(), symbols.end(),
        [](char left, char right) {

            if ((left >= 'a' && (right >= 'A' && right <= 'Z')) ||
                (right >= 'a' && (left >= 'A' && left <= 'Z')))
            {
                return left > right;
            }

            return left < right;
        });

    for (int i = 0; i < (int)symbols.size(); i++)
    {
        cout << symbols[i];
    }

    return 0;
}

