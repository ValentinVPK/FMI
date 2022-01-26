#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Compare {
    bool operator()(const int& a, const int& b)
    {
        return a > b;
    }
};

int main() {

    /* HEAP */
    priority_queue<int> pq; // max heap

    pq.push(5);
    pq.push(5);
    pq.push(15);
    pq.push(6);
    pq.push(1);
    pq.push(7);

    while (!pq.empty()) {
        cout << " " << pq.top();
        pq.pop();
    }
    cout << '\n';


    priority_queue <int, vector<int>, Compare > pq2; //min heap
    pq2.push(5);
    pq2.push(5);
    pq2.push(15);
    pq2.push(6);
    pq2.push(1);
    pq2.push(7);

    while (!pq2.empty()) {
        cout << " " << pq2.top();
        pq2.pop();
    }
    cout << '\n';

    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pqPairs;
    pqPairs.push({ 5,1 });
    pqPairs.push({ 5,6 });
    pqPairs.push({ 5,3 });
    pqPairs.push({ 5,13 });
    pqPairs.push({ 5,2 });
    pqPairs.push({ 6,2 });
    pqPairs.push({ 1,1 });
    pqPairs.push({ 15,1 });

    cout << pqPairs.size();

    while (!pqPairs.empty()) {
        cout << "\n" << pqPairs.top().first << " " << pqPairs.top().second;
        pqPairs.pop();
    }
    cout << '\n';

    return 0;
}