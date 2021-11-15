#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string word;
    int num, result = 0;
    char symbol;

    cin >> word;
    cin >> num;
    cin >> symbol;

    int length = word.length();
    if (num <= length) {
        for (int i = 0; i < length; i++)
        {
            if (word[i] == symbol) {
                result++;
            }
        }
    }
    else {
        int count = 0;
        for (int i = 0; i < length; i++)
        {
            if (word[i] == symbol) {
                count++;
            }
        }

        int times = num / length;
        int leftOver = num - times * length;

        result += count * times;

        for (int i = 0; i < leftOver; i++)
        {
            if (word[i] == symbol) {
                result++;
            }
        }
    }


    cout << result;
    return 0;
}
