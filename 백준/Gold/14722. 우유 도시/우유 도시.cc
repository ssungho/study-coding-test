#include <bits/stdc++.h>

using namespace std;

const int dy[2]{0, 1}, dx[2]{1, 0};
int n, ny, nx, a[1001][1001], dp[1001][1001][3];

int go(int y, int x, int k)
{
	if (y > n || x > n)
	{
		return 0;
	}

	if (dp[y][x][k] != -1)
	{
		return dp[y][x][k];
	}

	int& ret = dp[y][x][k];
	ret = 0;

	for (int i = 0; i < 2; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny > n || nx > n)
		{
			continue;
		}

		if (a[ny][nx] == k)
		{
			ret = max(ret, go(ny, nx, (k + 1) % 3) + 1);
		}
		ret = max(ret, go(ny, nx, k));
	}

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));

	int ans = 0;
	if (a[1][1] == 0)
	{
		ans = go(1, 1, 1) + 1;
	}
	else 
	{
		ans = go(1, 1, 0);
	}
	cout << ans << '\n';

	return 0;
}