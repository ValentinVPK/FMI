#include <vector>
#include <iostream>
using namespace std;

const int N = 1000;
bool visited[N];
int parent[N];
int adjMat[N][N];
vector<int>adjacencyList[N];
int  numberOfVertices, numberOfEdges;
int hamiltonPaths = 0, hamiltonCycles = 0;

void dfs(int v, int treeSize)
{
	if (treeSize == numberOfVertices) {

		hamiltonPaths++;
		cout << "Hamilton path\n";

		if (adjMat[v][0]) {

			hamiltonCycles++;
			cout << "Hamilton cycle\n";

		}

		while (v != -1) {

			cout << v << " ";
			v = parent[v];
		}

		cout << "\n\n";

		return;

	}

	visited[v] = 1;

	for (auto neighbour : adjacencyList[v])
	{
		if (!visited[neighbour]) {

			parent[neighbour] = v;

			dfs(neighbour, treeSize + 1);


		}

	}

	visited[v] = 0;

}


int main()
{
	int from = 0, to = 0;
	cin >> numberOfVertices >> numberOfEdges;
	while (numberOfEdges)
	{
		cin >> from >> to;
		adjacencyList[from].push_back(to);
		adjacencyList[to].push_back(from);
		adjMat[from][to] = 1;
		adjMat[to][from] = 1;
		numberOfEdges--;
	}

	parent[0] = -1;
	dfs(0, 1);

	cout << hamiltonPaths << " " << hamiltonCycles;

	return 0;
}

/*
5 8
0 1
0 2
0 4
1 2
1 4
2 3
2 4
3 4
!highlight!*/