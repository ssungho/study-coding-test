#include <bits/stdc++.h>
using namespace std;

using edge = pair<int, int>;
int n, m, a, b, u, v, w;
vector<vector<edge>> graph;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	graph.resize(n + 1);

	vector<int> costs(n + 1, INT_MAX);

	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
	}

	cin >> a >> b;

	priority_queue<edge, vector<edge>, greater<>> pq;
	costs[a] = 0;
	pq.push({0, a});

	while (!pq.empty())
	{
		int cur_cost = pq.top().first;
		int cur_v = pq.top().second;
		pq.pop();

		if (cur_cost > costs[cur_v])
		{
			continue;
		}

		const auto& adj = graph[cur_v];
		for (const auto& p : adj)
		{
			int next_v = p.first;
			int weight = p.second;
			if (costs[next_v] > cur_cost + weight)
			{
				costs[next_v] = cur_cost + weight;
				pq.push({costs[next_v], next_v});
			}
		}
	}

	cout << costs[b] << '\n';

	return 0;
}