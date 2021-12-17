#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

const int N = 1000;

vector<int> adjacencyList[N];
int dist[N]; //shortest paths from source to all vertices

vector<int> parent[N];

vector<vector<int> > paths;
vector<int> path;



void findPaths(int v) {

	if (v == -1)
	{
		paths.push_back(path);
		return;
	}

	for (auto par : parent[v]) {

		path.push_back(v);

		findPaths(par);
		path.pop_back();
	}

}

void bfs(int v)
{
	for (int i = 0; i < N; i++)dist[i] = INT_MAX;
	dist[v] = 0;
	parent[v].push_back(-1);
	queue<int> q;
	q.push(v);
	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		for (auto neighbourOfCurrentV : adjacencyList[current])
		{

			if (dist[neighbourOfCurrentV] > dist[current] + 1)
			{

				parent[neighbourOfCurrentV].clear();
				parent[neighbourOfCurrentV].push_back(current);

				dist[neighbourOfCurrentV] = dist[current] + 1;
				q.push(neighbourOfCurrentV);
			}
			else if (dist[neighbourOfCurrentV] == dist[current] + 1) {
				parent[neighbourOfCurrentV].push_back(current);
			}
		}
	}
}



int main()
{
	int n, m;
	cin >> n >> m;
	while (m) {
		int a, b;
		cin >> a >> b;
		adjacencyList[a].push_back(b);
		adjacencyList[b].push_back(a);
		m--;
	}

	bfs(0);
	findPaths(5);

	for (int i = 0; i < n; i++) cout << dist[i] << " ";

	cout << endl;

	for (auto v : paths) {
		reverse(v.begin(), v.end());
		for (int u : v) cout << u << " ";
		cout << endl;
	}
	return 0;
}
/*
7 9
0 1
0 2
0 6
6 4
1 4
2 3
3 5
4 5
1 3
!highlight!*/