#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string input;
    char symbol;

    cin >> input;
    cin >> symbol;

    vector<int> places;

    for (size_t i = 0; i < input.length(); i++)
    {
        char currSymbol = input[i];
        if (currSymbol == symbol) {
            places.push_back(0);
        }
        else {
            int leftIndex = -1;
            int rightIndex = -1;
            for (int j = i; j >= 0; j--)
            {
                if (input[j] == symbol) {
                    leftIndex = j;
                    break;
                }
            }

            for (int j = i; j < input.length(); j++)
            {
                if (input[j] == symbol) {
                    rightIndex = j;
                    break;
                }
            }

            int leftCount = i - leftIndex;
            int rightCount = rightIndex - i;
            if (rightIndex == -1) {
                places.push_back(leftCount);
            }
            else if (leftIndex == -1) {
                places.push_back(rightCount);
            }
            else {
                if (leftCount < rightCount) {
                    places.push_back(leftCount);
                }
                else {
                    places.push_back(rightCount);
                }
            }
        }
    }

    for (size_t i = 0; i < places.size(); i++)
    {
        cout << places[i] << " ";
    }


    return 0;
}

