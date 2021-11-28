
#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int len(int num)
{
    int result = 0;

    while (true)
    {
        if (num == 0)
        {
            //result++;
            break;
        }

        result++;
        num /= 2;
    }

    return result;
}
string decToBinary(int num, int len)
{
    string binary;
    while (num != 0) 
    {
        binary += (num % 2 == 0 ? "0" : "1");
        num /= 2;
    }

    while (binary.length() < len)
    {
        binary += '0';
    }

    reverse(binary.begin(), binary.end());
    return binary;
}

void fillSet(string binary, int index, set<string>& resultSet)
{
    if (index == binary.size())
    {
        resultSet.insert(binary);
        return;
    }

    if (binary[index] == '1')
    {
        binary[index] = '0';
        fillSet(binary, index + 1, resultSet);

        binary[index] = '1';
        fillSet(binary, index + 1, resultSet);
    }
    else
    {
        fillSet(binary, index + 1, resultSet);
    }
}

int main()
{
    vector<int> inputNumbers;
    set<string> uniqueBinaryNumbers;

    int N;
    cin >> N;

    int num;
    int result = 0;
    int maxLen = 0;
    for (size_t i = 0; i < N; i++)
    {
        cin >> num;
        
        inputNumbers.push_back(num);
        int currLen = len(num);

        if (currLen > maxLen)
        {
            maxLen = currLen;
        }
    }

    for (size_t i = 0; i < inputNumbers.size(); i++)
    {
        string binary = decToBinary(inputNumbers[i], maxLen);

        fillSet(binary, 0, uniqueBinaryNumbers);
    }

    cout << uniqueBinaryNumbers.size();
    return 0;
}


