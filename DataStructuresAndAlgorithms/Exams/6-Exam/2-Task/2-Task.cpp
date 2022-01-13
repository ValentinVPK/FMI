#include <utility>
#include <vector>
#include <queue>
#include <iostream>
#include <climits>
#include <algorithm>
#include <list>
#include <map>
using namespace std;

class MyGraph {
    int node;

    list<int>* adjacencyList;

    void dfs(int start, bool visited[])
    {
        visited[start] = true;

        for (auto i = adjacencyList[start].begin(); i != adjacencyList[start].end(); ++i)
            if (!visited[*i])
                dfs(*i, visited);
    }

public:
    MyGraph(int V) 
    {
        this->node = V;
        adjacencyList = new list<int>[V];
    }

    void addEdge(int v, int w)
    {
        adjacencyList[v].push_back(w);
        adjacencyList[w].push_back(v);
    }
    int connectedCOmponents()
    {
        bool* visited = new bool[node];

        int result = 0;
        for (size_t i = 0; i < node; i++)
        {
            visited[i] = false;
        }
            
        for (size_t i = 0; i < node; i++) {
            if (visited[i] == false) {
                dfs(i, visited);
                result += 1;
            }
        }

        return result;
    }
};


int main()
{
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; ++i)
    {
        int fromNode, ToNode;
        cin >> fromNode >> ToNode;

        MyGraph g(fromNode);

        for (int j = 0; j < ToNode; ++j)
        {
            int a, b;
            cin >> a >> b;
            g.addEdge(a, b);
        }

        cout << g.connectedCOmponents() << " ";
    }

    return 0;
}


