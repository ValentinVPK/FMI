#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<string, bool> visited;
unordered_map<string, vector<string>> adjacencyList;


//void dfs(int v)
//{
//	visited[v] = 1;
//	for (auto neighbour : adjacencyList[v])
//	{
//		if (!visited[neighbour]) dfs(neighbour);
//	}
//
//}

stack<string> s;
void dfs(string v)
{
	visited[v] = 1;
	for (auto neighbour : adjacencyList[v])
	{
		if (!visited[neighbour]) dfs(neighbour);
	}
	s.push(v);
}


void topologicalSort()
{
	for (auto neighbour : adjacencyList)
	{
		string cur = neighbour.first;
		if (!visited[cur]) dfs(cur);
	}
}


unordered_map<char, vector<char>> adjacencyList2;
unordered_map<char, bool> visited2;
stack<char> s2;
void topologicalSort2(char v)
{
	visited2[v] = 1;
	for (auto neighbour : adjacencyList2[v])
	{
		if (!visited2[neighbour]) topologicalSort2(neighbour);
	}
	s2.push(v);
}


int main()
{
	int n, m;
	cin >> n >> m;
	while (m--) {
		char from, to;
		cin >> from >> to;
		visited2[from] = 0;
		adjacencyList2[from].push_back(to);
	}

	topologicalSort2('A');

	while (!s2.empty()) {
		cout << s2.top() << " ";
		s2.pop();
	}
	/*
	7 9
A B
A C
B C
B D
C E
D E
D F
G E
G F

8 9
socks shoes
shorts shoes
shorts pants
pants shoes
pants belt
belt jacket
shirt belt
shirt tie
shirt jacket


	*/

	return 0;
}
