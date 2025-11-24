#include <bits/stdc++.h>
using namespace std;

int n, r, q, u, v;
vector<vector<int>> adj_list;
vector<vector<int>> tree;
int sub_size[100001];

void MakeTree(int current_node, int parent_node)
{
	for (int node : adj_list[current_node])
	{
		if (node != parent_node)
		{
			tree[current_node].push_back(node);
			MakeTree(node, current_node);
		}
	}
}

void CountSubtreeNodes(int current_node)
{
	sub_size[current_node] = 1;
	for (int node : tree[current_node])
	{
		CountSubtreeNodes(node);
		sub_size[current_node] += sub_size[node];
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> r >> q;
	adj_list.resize(n + 1);
	tree.resize(n + 1);

	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	MakeTree(r, -1);
	CountSubtreeNodes(r);

	for (int i = 0; i < q; i++)
	{
		int u_node;
		cin >> u_node;
		cout << sub_size[u_node] << '\n';
	}

	return 0;
}