#include <bits/stdc++.h>
using namespace std;

int n, t, m, job;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	vector<vector<int>> graph(n + 1);
	vector<int> indegrees(n + 1);
	vector<int> times(n + 1);
	vector<int> dp(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> times[i] >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> job;
			indegrees[i]++;
			graph[job].push_back(i);
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (indegrees[i] == 0)
		{
			q.push(i);
			dp[i] = times[i];
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto next : graph[cur])
		{
			dp[next] = max(dp[cur] + times[next], dp[next]);

			if (--indegrees[next] == 0)
			{
				q.push(next);
			}
		}
	}

	cout << *max_element(dp.begin() + 1, dp.end()) << '\n';

	return 0;
}