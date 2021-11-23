

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1000002;
vector<vector<int>> tree(N);

void depthFirstSearch(int value)
{
    cout << value << " ";

    for (auto x : tree[value])
    {
        depthFirstSearch(x);
    }
}

void levelOrderTraversal(int value)
{
    queue<int> q;
    q.push(value);

    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        cout << c << " ";


        for (auto neighbour : tree[c])
        {
            q.push(neighbour);
        }
    }

}

int main()
{
    int numOfNodes;
    cin >> numOfNodes;

    int parent, child;
    for (int i = 1; i <= numOfNodes - 1; i++)
    {
        
        cin >> parent >> child;

        tree[parent].push_back(child);
    }
}


