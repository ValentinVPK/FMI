#include <utility>
#include <vector>
#include <queue>
#include <iostream>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

const int N = 100001;
vector<pair<long, long>> weightAndTimeToNode(N, { LONG_MAX, LONG_MAX }); // kgs, time
vector<pair<long, pair<long, long>>>adjacencyList[N]; // node, pair(kgs, time)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long  nodes, edges, edgeValue, batteryTime;
    cin >> nodes >> edges >> batteryTime;

    long  fromNode, toNode, kgsToDrop, time;
    for (size_t i = 0; i < edges; i++)
    {
        cin >> fromNode >> toNode >> kgsToDrop >> time;
        adjacencyList[fromNode].push_back({ toNode, {kgsToDrop, time} });
    }

    weightAndTimeToNode[1].first = 0;
    weightAndTimeToNode[1].second = 0;
    

    priority_queue< pair<long, pair<long, long>>, vector <pair<long, pair<long, long>>>, 
        greater<pair<long, pair<long, long>>> > pq; // kgs pair(time, node)
    pq.push({ 0, {0, 1} });

    while (!pq.empty())
    {
        long currentNode = pq.top().second.second;
        long edgeTime = pq.top().second.first;
        long edgeKgs = pq.top().first;
        pq.pop();

        for (pair<long, pair<long, long>> neighbour : adjacencyList[currentNode])
        {

            long childNode = neighbour.first;
            long edgeToChildKgs = neighbour.second.first;
            long edgeToChildTime = neighbour.second.second;

            long correctKgs = edgeKgs > edgeToChildKgs ? edgeKgs : edgeToChildKgs;

            if (weightAndTimeToNode[childNode].first >= correctKgs
                && edgeTime + edgeToChildTime <= batteryTime)
            {
                weightAndTimeToNode[childNode].first = correctKgs;
                weightAndTimeToNode[childNode].second = edgeTime + edgeToChildTime;
                pq.push({ correctKgs, { edgeTime + edgeToChildTime, childNode} });
            }
            else if (edgeTime + edgeToChildTime > batteryTime)
            {
                weightAndTimeToNode[currentNode].first = LONG_MAX;
                weightAndTimeToNode[currentNode].second = LONG_MAX;
            }
        }
    }

    if (weightAndTimeToNode[nodes].first == LONG_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << weightAndTimeToNode[nodes].first;
    }

    return 0;

}