#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

const int N = 10000;
vector<int> adjacencyList[N];
bool visited[N]{ 0 };

//vector<int> adjacencyMatrix[N];


void bfs(int v)
{
	queue<int> q;
	visited[v] = 1;
	q.push(v);

	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		cout << current << " ";
		for (auto neighbour : adjacencyList[current])
		{
			if (!visited[neighbour])
			{
				visited[neighbour] = 1;
				q.push(neighbour);
			}
		}
	}
}


void dfs(int v)
{
	visited[v] = 1;
	cout << v << " ";
	for (auto neighbour : adjacencyList[v])
	{
		if (!visited[neighbour]) dfs(neighbour);
	}

}


/*
11 9
0 1
0 2
2 1

3 4
4 5

6 7
7 8
7 9
6 10
*/
int findNumberOfComponents(int numberOfVertices)
{
	int components = 0;
	for (int i = 0; i < numberOfVertices; i++)
	{
		if (!visited[i])
		{
			dfs(i);
			components++;
		}
	}
	return components;
}

int main()
{
	int n, m;
	cin >> n >> m;
	while (m--) {
		int from, to;
		cin >> from >> to;
		adjacencyList[from].push_back(to);
		adjacencyList[to].push_back(from);

		//adjacencyMatrix[from].push_back(to);
		//adjacencyMatrix[to].push_back(from);
	}

	int startVertex = 0;
	bfs(startVertex);

	cout << endl;
	for (int i = 0; i < N; i++) visited[i] = 0;

	//dfs(startVertex);

	//cout << findNumberOfComponents(n);

	return 0;
}
/*
8 9
0 1
0 3
1 4
2 3
4 3
1 5
5 2
5 6
6 7

!highlight!*/