#include <bits/stdc++.h>
using namespace std;

using edge = pair<int, pair<int, int>>;
int v, e, a, b, c, result, parent[10001];

int Find(int x)
{
	if (parent[x] == x)
	{
		return x;
	}

	return parent[x] = Find(parent[x]);
}

void Union(int l, int r)
{
	int parent_l = Find(l);
	int parent_r = Find(r);
	if (parent_l != parent_r)
	{
		if (parent_l < parent_r)
		{
			parent[parent_r] = parent_l;
		}
		else
		{
			parent[parent_l] = parent_r;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> v >> e;
	for (int i = 1; i <= v; i++)
	{
		parent[i] = i;
	}

	priority_queue<edge, vector<edge>, greater<>> pq;
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		pq.push({c, {a, b}});
	}

	while (!pq.empty())
	{
		edge cur = pq.top();
		pq.pop();

		int start = cur.second.first;
		int end = cur.second.second;
		int weight = cur.first;

		if (Find(start) != Find(end))
		{
			Union(start, end);
			result += weight;
		}
	}

	cout << result << '\n';

	return 0;
}