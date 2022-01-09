
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const int SIZE = 200001;

struct Edge {
    int from;
    int to;
    long long skill;
    long long moneyPerSkill;
    int index;

    bool operator <(const Edge& rhs) const 
    {
        if (this->skill == rhs.skill)
        {
            return make_pair(this->moneyPerSkill , this->to) > make_pair(rhs.moneyPerSkill, rhs.to);
        }
        else
        {
            return this->skill < rhs.skill;
        }
    }
};

int nodesCount, edgesCount;
vector<Edge> edges;

int parent[SIZE];
int depth[SIZE];
vector<int> edgesIndexes;

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

void kruskalAlgorithm() {
    
    int mstEdges = nodesCount;

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= nodesCount; i++) {
        parent[i] = i;
        depth[i] = 0;
    }

    for (Edge e : edges) {
        int root1 = findNode(e.from);
        int root2 = findNode(e.to);

        if (root1 != root2) {
            unite(root1, root2);

            mstEdges--;

            cout << e.index << endl;
        }

        if (mstEdges == 1) {
            break;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> nodesCount >> edgesCount;

    int from, to;
    long long skill, moneyPerSkill;

    for (int i = 1; i <= edgesCount; i++)
    {
        cin >> from >> to >> skill >> moneyPerSkill;
        edges.push_back({ from,to,skill,moneyPerSkill,i });
    }

    kruskalAlgorithm();


    return 0;
}


