
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> integers;

    int n;
    cin >> n;

    for (size_t i = 0; i < n; i++) {
        int number;
        cin >> number;
        integers.push_back(number);
    }

    int sum = 0;
    for (int number : integers) {
        sum += number;
    }

    double result = (sum * 1.0) / integers.size();
    cout << result << endl;     
}


