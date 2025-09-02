#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> visited;

bool DFS(int current, int count)
{
	if (count == 5)
	{
		return true;
	}

	bool result = false;

	for (int node : graph[current])
	{
		if (!visited[node])
		{
			visited[node] = true;
			result = DFS(node, count + 1);
			if (result)
			{
				break;
			}
			visited[node] = false;
		}
	}

	return result;
}

int main(void)
{
	cin >> n >> m;
	graph.resize(n);
	visited.resize(n);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int result = 0;
	for (int i = 0; i < n; i++)
	{
		visited.clear();
		visited.resize(n);
        
		visited[i] = true;
		if (DFS(i, 1))
		{
			result = 1;
			break;
		}
	}

	cout << result << '\n';

	return 0;
}