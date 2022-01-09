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
vector<long> distanceToNode(N, LONG_MAX );
vector<pair<long, long>>adjacencyList[N];

int main()
{
    long  nodes, edges;
    cin >> nodes >> edges;

    long  fromNode, toNode, distance;
    for (size_t i = 0; i < edges; i++)
    {
        cin >> fromNode >> toNode >> distance;
        adjacencyList[fromNode].push_back({ toNode, distance});
        adjacencyList[toNode].push_back({ fromNode, distance });
    }



    long tSetCount;
    cin >> tSetCount;
    long currNode;
    priority_queue< pair<long, long>, vector <pair<long, long>>, greater<pair<long, long>> > pq;
    for (size_t i = 0; i < tSetCount; i++)
    {
        cin >> currNode;
        pq.push({0, currNode});
        distanceToNode[currNode] = 0;
    }

    while (!pq.empty())
    {
        long currentNode = pq.top().second;
        long edgeValueToCurrent = pq.top().first;
        pq.pop();

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

    long querries;
    cin >> querries;
    long sSetNode;
    for (size_t i = 0; i < querries; i++)
    {
        cin >> sSetNode;
        cout << distanceToNode[sSetNode] << endl;
    }

    return 0;
}
