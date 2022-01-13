
#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int N = 1000;
int adjMatrix[N][N];
char maze[N][N];
map<pair<int,int>, vector<pair<int, int>>> adjMap;
pair<int, int> startingNode;
pair<int, int> endingNode;
int correctPathsCount = 0;
int numberOfNodes = 0;

map<pair<int, int>, int> visited;

void dfs(pair<int,int> node, int treeSize)
{
	if (treeSize == numberOfNodes) 
	{
		if(node.first == endingNode.first && node.second == endingNode.second) correctPathsCount++;
		return;
	}

	visited[node] = 1;

	for (auto neighbour : adjMap[node])
	{
		if (!visited[neighbour]) 
		{
			dfs(neighbour, treeSize + 1);
		}

	}

	visited[node] = 0;

}


int main()
{
    int rows, cols;
    cin >> rows >> cols;

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cin >> maze[i][j];

			if (maze[i][j] != 'x')
			{
				visited[{i, j}] = 0;
				numberOfNodes++;
			}

			if (maze[i][j] == 's')
			{
				startingNode = { i, j };
			}

			if (maze[i][j] == 'e')
			{
				endingNode = { i, j };
			}
		}
	}


	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (maze[i][j] == 'x') continue;

			if (i - 1 >= 0 && maze[i - 1][j] != 'x') adjMap[{i, j}].push_back({ i - 1, j });

			if (i + 1 < rows && maze[i + 1][j] != 'x') adjMap[{i, j}].push_back({ i + 1, j });

			if(j - 1 >= 0 && maze[i][j - 1] != 'x') adjMap[{i, j}].push_back({ i, j - 1 });

			if (j + 1 < cols && maze[i][j + 1] != 'x') adjMap[{i, j}].push_back({ i, j + 1 });

		}
	}

	dfs(startingNode, 1);

	cout << correctPathsCount;

	return 0;

}


