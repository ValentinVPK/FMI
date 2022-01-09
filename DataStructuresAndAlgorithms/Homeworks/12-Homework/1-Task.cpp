
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static const int SIZE = 1001;
int parent[SIZE];
int sizes[SIZE];
int nodesCount, edgesCount;

void makeNode(int node)
{
    parent[node] = node;
    sizes[node] = 1;
}

int findNode(int node)
{
    if (node == parent[node])
    {
        return node;
    }

    int root = findNode(parent[node]);

    parent[node] = root;

    return root;
}

void uniteNodes(int first, int second)
{
    first = findNode(first);
    second = findNode(second);

    if (first != second) 
    {
        if (sizes[first] < sizes[second])
        {
            swap(first, second);
        }

        parent[second] = first;
        sizes[first] += sizes[second];
    }
}

bool answerQuery(int first, int second)
{
    first = findNode(first);
    second = findNode(second);

    return first == second;
}

int main()
{
    cin >> nodesCount >> edgesCount;

    for (size_t i = 1; i <= nodesCount; i++)
    {
        makeNode(i);
    }

    int fromNode, toNode;

    for (size_t i = 0; i < edgesCount; i++)
    {
        cin >> fromNode >> toNode;
        uniteNodes(fromNode, toNode);
    }

    int queries;
    vector<int> resultVec;
    cin >> queries;

    int queryType;
    for (size_t i = 0; i < queries; i++)
    {
        cin >> queryType >> fromNode >> toNode;
        if (queryType == 1)
        {
            resultVec.push_back(answerQuery(fromNode, toNode));
        }
        else if (queryType == 2)
        {
            uniteNodes(fromNode, toNode);
        }
    }

    for (size_t i = 0; i < resultVec.size(); i++)
    {
        cout << resultVec[i];
    }

    return 0;
}


