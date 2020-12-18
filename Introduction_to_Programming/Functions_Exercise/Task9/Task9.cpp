
#include <iostream>
using namespace std;

int AskUser(const int start, const int end) {
    int number;
    cin >> number;
    while (number < start || number > end) {
        cin >> number;
    }

    return number;
}
int main()
{
    int start, end;
    cin >> start >>  end;

    cout << AskUser(start, end);
    
}

