#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    map<int, int> mp;
    mp.insert({ -1,100 });  // Insert or change with key-value pair
    mp[12] = 144;                         // Insert or change by key
    mp[10] = 14;                         // Insert or change by key
    mp[22] = 1000;                       // Insert or change by key
    mp.erase(-1);                         // Remove element by key
    bool mp_count5 = mp.count(12);         // Count occurrences of key, always 1 or 0
    auto mp_five = mp.find(5);            // Iterator to the element if found, mp.end() otherwise

    // Iterate map where mp_el is (key,value)
    for (auto mp_el : mp) {
        cout << mp_el.first << ":" << mp_el.second << '\n';
    }

    map<int, int, greater<int> > mp2(mp.begin(), mp.end());

    cout << endl;
    for (auto mp_el : mp2) {
        cout << mp_el.first << ":" << mp_el.second << endl;
    }

    mp.clear();                           // Remove all elements

}