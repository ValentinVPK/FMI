#include <iostream>
#include <vector>
using namespace std;

const int N = 100000;
vector<int> degreeVec(N);
vector<int> visited(N, 0);
vector<int> adjList[N];

void DFS(int node)
{
    visited[node] = true;

    for (auto neighbour : adjList[node])
    {
        if (visited[neighbour] == false)
        {
            DFS(neighbour);
        }
    }
}


int main() {

    int queriesAmount = 0;
    cin >> queriesAmount;

    int edgesAmount = 0, nodesAmount = 0;
    int fromNode = 0, toNode = 0;
    for (size_t q = 0; q < queriesAmount; q++)
    {
        int oddDegreeNodesAmount = 0;
        cin >> nodesAmount >> edgesAmount;

        for (size_t i = 0; i < N; i++)
        {
            degreeVec[i] = 0;
            visited[i] = false;
            adjList[i].clear();
        }

        for (size_t i = 0; i < edgesAmount; i++)
        {
            cin >> fromNode >> toNode;
            degreeVec[toNode]++;
            degreeVec[fromNode]++;

            adjList[fromNode].push_back(toNode);
            adjList[toNode].push_back(fromNode);
        }

        DFS(toNode);

        int visitedCount = 0;
        for (size_t i = 0; i < N; i++)
        {
            if (visited[i])
            {
                visitedCount++;
            }
        }

        if (visitedCount != nodesAmount)
        {
            cout << "none" << endl;
            continue;
        }

        for (size_t i = 0; i < N; i++)
        {
            if (degreeVec[i] % 2 != 0)
            {
                oddDegreeNodesAmount++;
            }
        }

        if (oddDegreeNodesAmount == 0)
        {
            cout << "ecycle" << endl;
        }
        else if (oddDegreeNodesAmount == 2)
        {
            cout << "epath" << endl;
        }
        else
        {
            cout << "none" << endl;
        }
    }

    return 0;
}