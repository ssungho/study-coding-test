#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, k;
int in_degrees[101], dp[101][101];

vector<vector<pair<int, int>>> v;

int main(void)
{
	cin >> n;
	v.resize(n + 1);

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> k;
		v[y].push_back({x, k});
		in_degrees[x]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (in_degrees[i] == 0)
		{
			dp[i][i] = 1;
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto& p : v[cur])
		{
			int next = p.first;
			int cnt = p.second;

			for (int i = 1; i <= n; i++)
			{
				dp[next][i] += dp[cur][i] * cnt;
			}

			if (--in_degrees[next] == 0)
			{
				q.push(next);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (dp[n][i])
		{
			cout << i << ' ' << dp[n][i] << '\n';
		}
	}

	return 0;
}