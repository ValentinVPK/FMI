#include <utility>
#include <vector>
#include <queue>
#include <iostream>
#include <climits>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

const int N = 100001;
vector<long> distanceToNode(N, LONG_MAX);
vector<pair<long, long>>adjacencyList[N];

void shortestPathDijkstra(long startNode) 
{
    priority_queue< pair<long, long>, vector <pair<long, long>>, greater<pair<long, long>> > pq;
    distanceToNode[startNode] = 0;
    pq.push({ 0, startNode });

    while (!pq.empty())
    {
        long currentNode = pq.top().second;
        long edgeValueToCurrent = pq.top().first;
        pq.pop();

        if (edgeValueToCurrent > distanceToNode[currentNode])
        {
            continue;
        }

        for (pair<long, long> neighbour : adjacencyList[currentNode])
        {
            long childNode = neighbour.first;
            long edgeValueToChildNode = neighbour.second;

            if (distanceToNode[childNode] > edgeValueToCurrent + edgeValueToChildNode)
            {
                distanceToNode[childNode] = edgeValueToCurrent + edgeValueToChildNode;
                pq.push({ edgeValueToChildNode + edgeValueToCurrent, childNode });
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long  nodes, edges;
    cin >> nodes >> edges;

    long  fromNode, toNode, distance;
    for (size_t i = 0; i < edges; i++)
    {
        cin >> fromNode >> toNode >> distance;
        adjacencyList[fromNode].push_back({ toNode, distance });
        adjacencyList[toNode].push_back({ fromNode, distance });
    }

    shortestPathDijkstra(0);

    for (int i = 0; i < nodes; i++)
    {
        cout << distanceToNode[i] << " ";
    }
   
    return 0;
}
/*
9 14
0 1 4
0 7 8
1 2 8
1 7 11
7 8 7
7 6 1
2 8 2
2 3 7
2 5 4
8 6 6
6 5 2
5 3 14
5 4 10
3 4 9
*/
