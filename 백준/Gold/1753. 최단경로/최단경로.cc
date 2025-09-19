#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> costs;

int V, E, K;
int u, v, w;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> V >> E >> K;

	graph.resize(V + 1);
	costs.resize(V + 1, INT_MAX);

	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back({w, v});
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, K});
	costs[K] = 0;

	while (!pq.empty())
	{
		int cur_cost = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if (costs[cur_node] < cur_cost)
		{
			continue;
		}

		for (auto &next : graph[cur_node])
		{
			int next_cost = next.first;
			int next_node = next.second;

			if (cur_cost + next_cost < costs[next_node])
			{
				costs[next_node] = cur_cost + next_cost;
				pq.push({costs[next_node], next_node});
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (costs[i] == INT_MAX)
		{
			cout << "INF\n";
		}
		else
		{
			cout << costs[i] << '\n';
		}
	}

	return 0;
}