#include <bits/stdc++.h>
using namespace std;

int n, m;
int open[2], a[21], dp[21][21][21];

int go(int here, int open1, int open2)
{
	if (here == m)
	{
		return 0;
	}

	int& ret = dp[here][open1][open2];
	if (ret != -1)
	{
		return ret;
	}

	int target = a[here];
	int cnt1 = abs(open1 - target);
	int cnt2 = abs(open2 - target);

	ret = min(cnt1 + go(here + 1, target, open2), cnt2 + go(here + 1, open1, target));
	return ret;
}

int main(void)
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> open[0] >> open[1] >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}

	cout << go(0, open[0], open[1]) << '\n';

	return 0;
}