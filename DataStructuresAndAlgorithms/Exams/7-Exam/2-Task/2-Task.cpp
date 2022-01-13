#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

struct Edge
{
    int fromNode;
    int toNode;
    int weight;

    Edge(int from, int to, int weight)
    {
        this->fromNode = from;
        this->toNode = to;
        this->weight = weight;
    }
};

int main()
{
    int nodes, edges, K, T, L;
    cin >> nodes >> edges;

    vector<vector<bool>> visited(nodes, vector<bool>(nodes, false));
    vector<Edge> edgesVec;
    unordered_set<int> hatedNumbers;

    int fromNode, toNode, weight;
    for (int i = 0; i < edges; i++)
    {
        cin >> fromNode >> toNode >> weight;

        edgesVec.push_back({ fromNode,toNode,weight });
    }

    cin >> K;

    for (int i = 0; i < K; i++)
    {
        cin >> fromNode;

        hatedNumbers.insert(fromNode);
    }

    for (int i = 0; i < edges; i++)
    {
        if (hatedNumbers.count(edgesVec[i].weight) == 0)
        {
            visited[edgesVec[i].fromNode][edgesVec[i].toNode] = true;
        }
    }

    cin >> T;

    bool hasPath = true;

    for (int i = 0; i < T; i++)
    {
        cin >> L;

        hasPath = true;
        vector<int> currPath(L);

        for (int j = 0; j < L; j++)
        {
            cin >> currPath[j];
        }

        for (int j = 0; j < L - 1; j++)
        {
            if (visited[currPath[j]][currPath[j + 1]] == false)
            {
                hasPath = false;

                break;
            }
        }

        if (!hasPath)
        {
            cout << '0';
        }
        else
        {
            cout << '1';
        }
    }
}