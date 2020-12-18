
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> randomNumbers;

    for (size_t i = 0; i < n; i++) {
        int number;
        cin >> number;
        randomNumbers.push_back(number);
    }

    int sum = 0;
    for (int number : randomNumbers) {
        sum += number;
    }

    double average = (sum * 1.0) / randomNumbers.size();

    vector<int> resultVector;

    for (size_t i = 0; i < n; i++) {
        if (randomNumbers[i] > average) {
            resultVector.push_back(i);
        }
    }
    
    for (int index : resultVector) cout << index << " ";
}

