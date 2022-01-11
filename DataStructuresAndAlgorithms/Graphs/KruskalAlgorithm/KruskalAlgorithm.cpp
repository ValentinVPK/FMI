#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const int SIZE = 200001;

struct Edge {
    int from;
    int to;
    int cost;

    bool operator <(const Edge& rhs) const
    {
        return make_pair(cost, to) < make_pair(rhs.cost, rhs.to);
    }
};

int nodesCount, edgesCount;
vector<Edge> edges;
int parent[SIZE];
int depth[SIZE];
vector<pair<int, int>> mst[SIZE];

int findNode(int node) {
    if (node == parent[node]) {
        return node;
    }

    int root = findNode(parent[node]);

    parent[node] = root;

    return root;
}

void unite(int x, int y) {
    if (depth[x] > depth[y]) {
        parent[y] = x;
    }
    else if (depth[y] > depth[x]) {
        parent[x] = y;
    }
    else {
        parent[y] = x;
        depth[x]++;
    }
}

int kruskalAlgorithm() 
{
    int totalWeight = 0;
    int mstEdges = nodesCount;

    sort(edges.begin(), edges.end());

    for (int i = 0; i < nodesCount; i++) {
        parent[i] = i;
        depth[i] = 0;
    }

    for (Edge e : edges) {
        int root1 = findNode(e.from);
        int root2 = findNode(e.to);

        if (root1 != root2) 
        {
            unite(root1, root2);

            mst[e.from].push_back({ e.to, e.cost });
            mst[e.to].push_back({ e.from, e.cost });

            mstEdges--;
            totalWeight += e.cost;
        }

        if (mstEdges == 1) {
            break;
        }
    }

    if (mstEdges > 1) {
        cerr << "Graph is disjoined.\n";
        return -1;
    }


    return totalWeight;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> nodesCount >> edgesCount;

    int from, to, cost;

    for (int i = 0; i < edgesCount; i++)
    {
        cin >> from >> to >> cost;
        edges.push_back({ from,to});
    }

    kruskalAlgorithm();


    return 0;
}