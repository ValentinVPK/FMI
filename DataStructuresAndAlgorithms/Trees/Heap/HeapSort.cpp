#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> v = { 2, 8, 3, 9, 4, 15, 10, 3, 7, 9, 6, 5, 2, 10 };

    make_heap(v.begin(), v.end());


    for (int i = 0; i < v.size(); i++) {

        pop_heap(v.begin(), v.end() - i);

    }

    //  sort_heap(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {

        cout << v[i] << " ";

    }


    return 0;
}