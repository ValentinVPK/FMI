
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;

static const int SIZE = 100001;

struct Edge {
    int from;
    int to;
    int speed;

    bool operator <(const Edge& rhs) const
    {
        return make_pair(speed, to) < make_pair(rhs.speed, rhs.to);
    }
};

int nodesCount, edgesCount; 
vector<Edge> edges;

int parent[SIZE];
int depth[SIZE];
int currMinSpeed = INT_MAX, currMaxSpeed = 0;

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

bool kruskalAlgorithm() {
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

            if (e.speed < currMinSpeed)
            {
                currMinSpeed = e.speed;
            }

            if (e.speed > currMaxSpeed)
            {
                currMaxSpeed = e.speed;
            }
        }

        if (mstEdges == 1) {
            break;
        }
    }

    if (mstEdges > 1)
    {
        return false;
    }

    return true;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> nodesCount >> edgesCount;

    int from, to, speed;

    vector<Edge> tempEdges;
    for (size_t i = 1; i <= edgesCount; i++)
    {
        cin >> from >> to >> speed;
        edges.push_back({ from,to,speed });
        tempEdges.push_back({ from,to,speed });
    }

    kruskalAlgorithm();
    edges.erase(edges.begin());

    int minSpeed = currMinSpeed;
    int maxSpeed = currMaxSpeed;
    int difference = maxSpeed - minSpeed;

    currMinSpeed = INT_MAX;
    currMaxSpeed = 0;
    while (true)
    {
        bool isKruskalCorrect = kruskalAlgorithm();

        if (!isKruskalCorrect)
        {
            break;
        }

        edges.erase(edges.begin());
        
        int currDifference = currMaxSpeed - currMinSpeed;
        if (currDifference < difference)
        {
            minSpeed = currMinSpeed;
            maxSpeed = currMaxSpeed;
            difference = currDifference;
        }

        currMinSpeed = INT_MAX;
        currMaxSpeed = 0;
    }


    cout << minSpeed << " " << maxSpeed;
    return 0;
}



