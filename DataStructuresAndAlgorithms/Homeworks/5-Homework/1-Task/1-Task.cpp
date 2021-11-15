
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string inputStr;
    cin >> inputStr;
    int size = inputStr.size();

    stack<int> indexes;

    for (int i = size - 1; i >= 0; i--)
    {
        indexes.push(i);

        for (int j = 0; j < i; j++)
        {
            if (inputStr[j] == inputStr[i] )
            {
                indexes.pop();
                break;
            }
        }
        
        if (indexes.size() == 0 || indexes.top() != i)
        {
            continue;
        }

        for (int j = i + 1; j < size; j++)
        {
            if (inputStr[j] == inputStr[i])
            {
                indexes.pop();
                break;
            }
        }
    }


    while (!indexes.empty())
    {
        printf("%d ", indexes.top());
        indexes.pop();
    }
}

