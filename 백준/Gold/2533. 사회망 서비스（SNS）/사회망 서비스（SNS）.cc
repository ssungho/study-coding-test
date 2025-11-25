#include <bits/stdc++.h>
using namespace std;

int n, u, v;

vector<vector<int>> adj_list;
vector<vector<int>> dp;

void go(int current, int parent)
{
	dp[current][0] = 0; // current가 얼리 아답터가 아니다.
	dp[current][1] = 1; // current가 얼리 아답터다.
	
	for (int next : adj_list[current])
	{
		if (next == parent)
		{
			continue;
		}

		go(next, current);

		dp[current][0] += dp[next][1];
		dp[current][1] += min(dp[next][0], dp[next][1]);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
		
	cin >> n;
	adj_list.resize(n + 1);

	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	dp.resize(n + 1, vector<int>(2));
	go(1, -1);
	cout << min(dp[1][0], dp[1][1]) << '\n';

	return 0;
}