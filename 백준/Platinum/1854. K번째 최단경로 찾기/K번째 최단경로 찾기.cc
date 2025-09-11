#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int a, b, c;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m >> k;

	vector<vector<pair<int, int>>> graph(n + 1);
	vector<priority_queue<int>> costs(n + 1);

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, 1});

	costs[1].push(0);

	while (!pq.empty())
	{
		int cur_cost = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		for (auto &next : graph[cur_node])
		{
			int next_node = next.first;
			int next_cost = next.second;
			int new_cost = cur_cost + next_cost;

			if (costs[next_node].size() < k)
			{
				costs[next_node].push(new_cost);
				pq.push({new_cost, next_node});
			}
			else if (costs[next_node].top() > new_cost)
			{
				costs[next_node].pop();
				costs[next_node].push(new_cost);
				pq.push({new_cost, next_node});
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		while (costs[i].size() > k)
		{
			costs[i].pop();
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (costs[i].size() < k)
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << costs[i].top() << '\n';
		}
	}

	return 0;
}