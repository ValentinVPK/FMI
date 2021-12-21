
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

bool hasCycle(map<int, vector<int>>& graph, int numberOfNodes)
{
    queue<int> myQueue;
    map<int, int> mapCount;

    for (auto i : graph)
    {
        if (!mapCount.count(i.first)) 
        {
            mapCount[i.first] = 0;
        }
        for (auto j : i.second)
        {
            mapCount[j]++;
        }
    }

    for (auto i : mapCount)
    {
        if (i.second == 0)
        {
            myQueue.push(i.first);
        }
    }

    int currCount = 0;
    while (!myQueue.empty())
    {
        int currNode = myQueue.front();
        myQueue.pop();
        currCount++;
        for (auto j : graph[currNode])
        {
            mapCount[j]--;
            if (mapCount[j] == 0)
            {
                myQueue.push(j);
            }
        }
    }


    return currCount != numberOfNodes;

}

int main()
{
    vector<int> results;
    int Q;
    cin >> Q;

    int edgesCount;
    for (size_t i = 0; i < Q; i++)
    {
        cin >> edgesCount;
        map<int, vector<int>> myGraph;

        int first, second;
        for (size_t j = 0; j < edgesCount; j++)
        {
            cin >> first >> second;
            myGraph[first].push_back(second);

            if (!myGraph.count(second)) 
            {
                myGraph[second] = vector<int>();
            }
        }

        results.push_back(hasCycle(myGraph, myGraph.size()));
    }


    for (size_t i = 0; i < results.size(); i++)
    {
        cout << results[i] << " ";
    }
    return 0;
}


