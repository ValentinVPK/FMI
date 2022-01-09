#include <utility>
#include <vector>
#include <queue>
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    const int N = 100001;
    vector<pair<long long, long long>> distanceToNode(N, { LLONG_MAX, 0 });
    vector<pair<long long, long long>>adjacencyList[N];

    long long nodes, edges, edgeValue;
    long long fromNode, toNode;

    cin >> nodes >> edges;


    for (size_t i = 0; i < edges; i++)
    {
        cin >> fromNode >> toNode >> edgeValue;
        adjacencyList[fromNode].push_back({ toNode, edgeValue });
    }

    distanceToNode[1].first = 0;
    distanceToNode[1].second = 1;

    priority_queue< pair<long long, long long>, vector <pair<long long, long long>>, greater<pair<long long, long long>> > pq;
    pq.push({ 0, 1 });

    while (!pq.empty())
    {
        long long currentNode = pq.top().second;
        long long edgeValueToCurrent = pq.top().first;
        pq.pop();

        for (pair<long long, long long> neighbour : adjacencyList[currentNode])
        {

            long long childNode = neighbour.first;
            long long edgeValueToChildNode = neighbour.second;

            if (distanceToNode[childNode].first > edgeValueToCurrent + edgeValueToChildNode)
            {
                distanceToNode[childNode].first = edgeValueToCurrent + edgeValueToChildNode;
                distanceToNode[childNode].second = distanceToNode[currentNode].second;
                pq.push({ edgeValueToChildNode + edgeValueToCurrent, childNode });
            }
            else if (distanceToNode[childNode].first == edgeValueToCurrent + edgeValueToChildNode)
            {
                distanceToNode[childNode].second += distanceToNode[currentNode].second;
                if (distanceToNode[childNode].second > 1000000007)
                {
                    distanceToNode[childNode].second = distanceToNode[childNode].second % 1000000007;
                }
            }
        }
    }


    if (distanceToNode[nodes].first == LLONG_MAX)
    {
        cout << -1 << " " << distanceToNode[nodes].second;
    }
    else
    {
        cout << distanceToNode[nodes].first << " " << distanceToNode[nodes].second;
    }

    return 0;
    
}