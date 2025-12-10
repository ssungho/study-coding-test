#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, result;
bool visited[501];
vector<vector<int>> adj_list;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	adj_list.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

	// num, depth
	queue<pair<int, int>> q;
	q.push({1, 0});
	visited[1] = true;

	while (q.size())
	{
		int here = q.front().first;
		int depth = q.front().second;
		q.pop();

		if (depth == 2)
		{
			break;
		}

		for (int next : adj_list[here])
		{
			if (visited[next])
			{
				continue;
			}

			q.push({next, depth + 1});
			visited[next] = true;
			result++;
		}
	}

	cout << result << '\n';

	return 0;
}