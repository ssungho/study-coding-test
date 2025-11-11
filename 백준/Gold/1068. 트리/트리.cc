#include <bits/stdc++.h>
using namespace std;

int n, delete_node, root, parent;
vector<vector<int>> children;

int go(int node)
{
	if (node == delete_node)
	{
		return 0;
	}

	const auto &nodes = children[node];

	if (nodes.size() == 0 || (nodes.size() == 1 && nodes[0] == delete_node))
	{
		return 1;
	}

	int cnt = 0;

	for (int node : nodes)
	{
		if (node != delete_node)
		{
			cnt += go(node);
		}
	}

	return cnt;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	children.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> parent;
		if (parent != -1)
		{
			children[parent].push_back(i);
		}
		else
		{
			root = i;
		}
	}

	cin >> delete_node;

	cout << go(root) << '\n';

	return 0;
}