
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;

    unordered_map<string, int> stringsCount;
    vector<string> allStrings;
    
    string currString;
    for (size_t i = 0; i < N; i++)
    {
        cin >> currString;

        if (!stringsCount.count(currString))
        {
            stringsCount[currString] = 1;
        }
        else
        {
            stringsCount[currString]++;
        }

        allStrings.push_back(currString);
    }


    for (size_t i = 0; i < N; i++)
    {
        cout << stringsCount[allStrings[i]] << " ";
    }

    return 0;
}

