#include <bits/stdc++.h>
using namespace std;

int n, m, u, v, l, r;

vector<vector<int>> adj_list;
vector<int> depth_list;
vector<int> parent_list;

void dfs(int current, int parent, int depth)
{
	depth_list[current] = depth;
	parent_list[current] = parent;

	for (int next : adj_list[current])
	{
		if (depth_list[next] == -1)
		{
			dfs(next, current, depth + 1);
		}
	}
}

int lca(int a, int b)
{
	while (depth_list[a] > depth_list[b])
	{
		a = parent_list[a];
	}

	while (depth_list[a] < depth_list[b])
	{
		b = parent_list[b];
	}
	
	while (a != b)
	{
		a = parent_list[a];
		b = parent_list[b];
	}

	return a;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	adj_list.resize(n + 1);
	depth_list.resize(n + 1, -1);
	parent_list.resize(n + 1, -1);

	for (int i = 1; i < n; i++)
	{
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	// current, parent, depth
	dfs(1, -1, 1);

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> l >> r;
		cout << lca(l, r) << '\n';
	}

	return 0;
}