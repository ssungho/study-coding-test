#include <iostream>
#include <vector>
using namespace std;

vector<int> nodes[1001];
bool visited[1001];

void DFS(int node)
{
	visited[node] = true;

	for (int i = 0; i < nodes[node].size(); i++)
	{
		int next_node = nodes[node][i];
		if (!visited[next_node])
			DFS(next_node);
	}

	return;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int node, edge;
	cin >> node >> edge;

	for (int i = 0; i < edge; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;

		nodes[node1].push_back(node2);
		nodes[node2].push_back(node1);
	}

	int count = 0;
	for (int i = 1; i < node + 1; i++)
	{
		if (!visited[i])
		{
			DFS(i);
			count++;
		}
	}

	cout << count;

	return 0;
}