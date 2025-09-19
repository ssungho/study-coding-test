#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int n, m, from, to, cost, start_pos, end_pos;

vector<vector<pii>> graph;
vector<int> costs;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	graph.resize(n + 1);
	costs.resize(n + 1, INT_MAX);

	for (int i = 0; i < m; i++)
	{
		cin >> from >> to >> cost;
		graph[from].push_back({cost, to});
	}

	cin >> start_pos >> end_pos;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, start_pos});
	costs[start_pos] = 0;

	while (!pq.empty())
	{
		int cur_cost = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if (cur_cost > costs[cur_node])
		{
			continue;
		}

		for (auto &next : graph[cur_node])
		{
			int next_cost = next.first;
			int next_node = next.second;
			int sum_cost = min(INT_MAX, cur_cost + next_cost);

			if (sum_cost < costs[next_node])
			{
				costs[next_node] = sum_cost;
				pq.push({sum_cost, next_node});
			}
		}
	}

	cout << costs[end_pos] << '\n';

	return 0;
}