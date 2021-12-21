#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

int main()
{
    int N;
    cin >> N;

    string word;
    vector<string> allWords;
    for (size_t i = 0; i < N; i++)
    {
        cin >> word;
        allWords.push_back(word);
    }

    unordered_map<char, int> symbolsCount;
    unordered_map<char, multiset<char>> symbolsGraph;

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < allWords[i].size(); j++)
        {
            symbolsCount[allWords[i][j]] = 0;
        }
    }

    for (size_t i = 1; i < allWords.size(); i++)
    {
        int j = 0;

        while (allWords[i - 1][j] == allWords[i][j])
        {
            j++;
        }

        if (j >= min(allWords[i - 1].size(), allWords[i].size()))
        {
            continue;
        }

        symbolsCount[allWords[i][j]]++;
        symbolsGraph[allWords[i - 1][j]].insert(allWords[i][j]);
    }

    vector<char> resultVec;

    for (size_t i = 0; i < symbolsCount.size(); i++)
    {
        char symbol = ' ';
        for (auto currCount : symbolsCount)
        {
            if (currCount.second == 0)
            {
                symbol = currCount.first;
                break;
            }
        }

        resultVec.push_back(symbol);
        symbolsCount[symbol]--;

        for (auto currNode : symbolsGraph[symbol])
        {
            symbolsCount[currNode]--;
        }
    }

    for (size_t i = 0; i < resultVec.size(); i++)
    {
        cout << resultVec[i] << " ";
    }

    return 0;
}


