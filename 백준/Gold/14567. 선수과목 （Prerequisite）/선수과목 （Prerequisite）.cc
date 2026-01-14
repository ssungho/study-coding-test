#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
int indegrees[1001], dp[1001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		indegrees[b]++;
	}

	queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++)
	{
		if (indegrees[i] == 0)
		{
			q.push({i, 0});
		}
	}

	while (!q.empty())
	{
		int sub = q.front().first;
		int cnt = q.front().second;
		q.pop();

		dp[sub] = cnt + 1;

		for (int next : graph[sub])
		{
			if (--indegrees[next] == 0)
			{
				q.push({next, cnt + 1});
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << dp[i] << ' ';
	}
	cout << '\n';

	return 0;
}