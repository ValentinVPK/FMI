
#include <iostream>
#include "Set.hpp"

int main()
{
    Set<int> set1;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.erase(3);
    Set<int> set2;

    set2.insert(1);
    set2.insert(2);
    set2.insert(3);
    set2.insert(4);
    set2.insert(5);
    Set<int> set = unioon(set1, set2);
    set1.print();
}

