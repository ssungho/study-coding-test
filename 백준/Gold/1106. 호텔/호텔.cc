#include <bits/stdc++.h>
using namespace std;

int c, n, a[21][2], dp[1001];

int go(int here)
{
	if (here >= c)
	{
		return 0;
	}

	int& ret = dp[here];
	if (dp[here] != -1)
	{
		return dp[here];
	}

	ret = INT_MAX;
	for (int i = 1; i <= n; i++)
	{
		ret = min(ret, go(here + a[i][1]) + a[i][0]);
	}

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> c >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i][0] >> a[i][1];
	}
	memset(dp, -1, sizeof(dp));
	cout << go(0) << '\n';

	return 0;
}