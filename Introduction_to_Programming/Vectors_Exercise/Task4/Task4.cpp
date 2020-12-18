
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> numbers;
    for (size_t i = 0; i < n; i++) {
        int number;
        cin >> number;
        numbers.push_back(number);
    }

    vector<int> result;

    for (size_t i = 0; i < numbers.size() - 1; i++) {
        int count = 1;
        for (size_t j = i + 1; j < numbers.size(); j++) {
            if (numbers[i] == numbers[j]) count++;
        }

        if (count > 1) {
            if(find(result.begin(), result.end(), numbers[i]) != result.end()) result.push_back(numbers[i]);
        }
    }
    for (int number : result) cout << number << " ";
}

