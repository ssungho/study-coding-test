#include <bits/stdc++.h>
using namespace std;

int n, a, b;
int people[10001], dp[10001][2];
vector<vector<int>> adj_list;

void go(int current, int parent)
{
	dp[current][0] = 0;
	dp[current][1] = people[current];

	for (int next : adj_list[current])
	{
		if (next != parent)
		{
			go(next, current);

			dp[current][0] += max(dp[next][0], dp[next][1]);
			dp[current][1] += dp[next][0];
		}
	}
}

int main(void)
{
	cin >> n;

	memset(dp, -1, sizeof(dp));
	adj_list.resize(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> people[i];
	}

	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

	go(1, -1);

	cout << max(dp[1][0], dp[1][1]) << '\n';

	return 0;
}