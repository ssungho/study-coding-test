#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> graph[1001]; // 2차원 백터
bool visited[1001];

void dfs(int node)
{
	visited[node] = true;
	cout << node << " ";
	for (int i = 0; i < graph[node].size(); i++)
	{
		if (!visited[graph[node][i]])
		{
			dfs(graph[node][i]);
		}
	}
}

void bfs(int node)
{
	visited[node] = true;
	cout << node << " ";
	queue<int> q;
	q.push(node);
	while (!q.empty())
	{
		int cur_node = q.front();
		q.pop();
		for (int i = 0; i < graph[cur_node].size(); i++)
		{
			if (visited[graph[cur_node][i]] == false)
			{
				visited[graph[cur_node][i]] = true;
				cout << graph[cur_node][i] << " ";
				q.push(graph[cur_node][i]);
			}
		}
	}
}

int main(void)
{
	int N, M, V;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}
	for (int i = 0; i < N; i++)
	{
		sort(graph[i + 1].begin(), graph[i + 1].end());
	}

	dfs(V);
	cout << '\n';

	for (int i = 0; i < sizeof(visited); i++)
		visited[i] = false;
	
	bfs(V);

	return 0;
}
