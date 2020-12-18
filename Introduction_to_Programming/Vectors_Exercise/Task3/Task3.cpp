
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> words;
    for (size_t i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }
    char letter;
    cin >> letter;
    vector<int> resultVector;
    for (size_t i = 0; i < n; i++) {
        if (words[i][0] == letter) resultVector.push_back(i);
    }

    for (int index : resultVector) cout << index << " ";
}

