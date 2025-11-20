#include <bits/stdc++.h>
using namespace std;

using edge = pair<int, pair<int, int>>;
int n, m, u, v, w;
vector<edge> edge_list;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	edge_list.resize(m);
	vector<long> costs(n + 1, LONG_MAX);
	costs[1] = 0;

	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		edge_list[i] = {w, {u, v}};
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int cost = edge_list[j].first;
			int start_v = edge_list[j].second.first;
			int end_v = edge_list[j].second.second;

			if (costs[start_v] == LONG_MAX)
			{
				continue;
			}

			if (costs[end_v] > costs[start_v] + cost)
			{
				costs[end_v] = costs[start_v] + cost;
			}
		}
	}

	bool has_cycle = false;
	for (int i = 0; i < m; i++)
	{
		int cost = edge_list[i].first;
		int start_v = edge_list[i].second.first;
		int end_v = edge_list[i].second.second;

		if (costs[start_v] != LONG_MAX && costs[end_v] > costs[start_v] + cost)
		{
			has_cycle = true;
			break;
		}
	}

	if (has_cycle == false)
	{
		for (int i = 2; i <= n; i++)
		{
			if (costs[i] == LONG_MAX)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << costs[i] << '\n';
			}
		}
	}
	else
	{
		cout << "-1\n";
	}

	return 0;
}