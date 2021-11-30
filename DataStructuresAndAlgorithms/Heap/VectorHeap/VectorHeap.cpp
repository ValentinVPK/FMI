#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int main() {

    vector<int> v = { 2, 8, 3, 9, 4, 15, 10, 3, 7, 9, 6, 5, 2, 10 };

    if (is_heap(v.begin(), v.end())) cout << "The container is heap ";
    else    cout << "The container is not heap";
    cout << endl;

    make_heap(v.begin(), v.end()); //convert a range in a container to a heap
   // make_heap(v.begin(), v.end(), greater<int>());

    if (is_heap(v.begin(), v.end())) cout << "The container is heap ";
    else    cout << "The container is not heap";
    cout << endl;

    cout << "The maximum element of heap is : ";
    cout << v.front() << endl;




    v.push_back(50);

    if (is_heap(v.begin(), v.end())) cout << "The container is heap ";
    else    cout << "The container is not heap";
    cout << endl;

    push_heap(v.begin(), v.end()); //push_heap() to reorder elements
    //push_heap(v.begin(), v.end(), greater<int>());


    cout << "The maximum element of heap after push is : ";
    cout << v.front() << endl;




    pop_heap(v.begin(), v.end()); //delete maximum element
    v.pop_back();

    cout << "The maximum element of heap after pop is : ";
    cout << v.front() << endl;

    return 0;
}