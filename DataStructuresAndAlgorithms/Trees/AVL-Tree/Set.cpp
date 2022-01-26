#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct compare {
    bool operator() (const pair<int, char>& x, const pair<int, char>& y) const {
        return x.second < y.second;
    }
};

int main()
{
    set<int> s;
    // Add elements
    s.insert(2);
    s.insert(5);
    s.insert(1);
    s.insert(8);
    s.insert(6);
    s.insert(13);
    s.insert(8);
    s.insert(8);

    int size = s.size();                // Get the size
    s.erase(8);                         // Remove element

    bool s_count = s.count(5);         // Count occurrences, always 1 or 0
    bool s_count2 = s.count(4);         // Count occurrences, always 1 or 0

    auto s_hook = s.find(5);          // Valid iterator to the element if found, otherwise s.end()
    auto s_hook2 = s.find(4);          // Valid iterator to the element if found, otherwise s.end()


    auto s_lower = s.lower_bound(4);  // Iterator to the first element >= 4
    auto s_lower2 = s.lower_bound(5);  // Iterator to the first element >= 4

    auto s_upper = s.upper_bound(4);  // Iterator to the first element > 4
    auto s_upper2 = s.upper_bound(5);  // Iterator to the first element > 5

    s_lower++;
    s_lower++;
    s_lower--;


    // Iterate set
    for (auto set_cur_element : s) {
        cout << set_cur_element << ' ';
    }
    cout << endl;


    // Iterate set
    set<int>::iterator itr;
    for (itr = s.begin(); itr != s.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;

    int s_min = *s.begin();            // Get min element, first element in set
    int s_max = *s.rbegin();           // Get max element, last element in set


    //--------------------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------------------------

    set<int, greater<int> > s1(s.begin(), s.end());

    set<int, greater<int> >::iterator itr1;
    for (auto itr1 = s1.begin(); itr1 != s1.end(); itr1++)
    {
        cout << *itr1 << " ";
    }
    cout << endl;

    s.clear();                          // Remove all elements

    //--------------------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------------------------

    set<  pair<int, char>  > s2;
    s2.insert({ 8,'I' });
    s2.insert({ 6,'A' });
    s2.insert({ 3,'C' });
    s2.insert({ 2,'D' });
    s2.insert({ 12,'B' });

    cout << endl;
    // Iterate set
    for (auto set_cur_element : s2) {
        cout << set_cur_element.first << ' ' << set_cur_element.second << endl;
    }

    auto element = s2.find({ 6,'A' });
    cout << (*element).first << ' ' << (*element).second << endl;

    //--------------------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------------------------

    set<pair<int, char>, compare> s3;
    s3.insert({ 8,'I' });
    s3.insert({ 6,'A' });
    s3.insert({ 3,'C' });
    s3.insert({ 2,'D' });
    s3.insert({ 12,'B' });

    cout << endl;
    // Iterate set
    for (auto set_cur_element : s3) {
        cout << set_cur_element.first << ' ' << set_cur_element.second << endl;
    }

    //--------------------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------------------------

    multiset<int> ms;

    ms.insert(1);
    ms.insert(3);
    ms.insert(4);
    ms.insert(2);
    ms.insert(2);

    !highlight!cout << "\nElements in Multiset:\n";
    for (auto it : ms)
        cout << it << " ";

    //unordered_set SOON
}