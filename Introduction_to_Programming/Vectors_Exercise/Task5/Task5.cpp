
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int vectorSize;
    cin >> vectorSize;
    vector<int> v1(vectorSize);
    vector<int> v2(vectorSize);
 
    for (size_t i = 0; i < vectorSize; i++) {
        cin >> v1[i];
    }

    for (size_t i = 0; i < vectorSize; i++) {
        cin >> v2[i];
    }


}

