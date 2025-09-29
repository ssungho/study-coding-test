#include <bits/stdc++.h>

using namespace std;

int dy[4]{-1, 1, 0, 0}, dx[4]{0, 0, -1, 1};
int n, ny, nx, a[500][500], dp[500][500];
int max_cnt = 0;

int dfs(int y, int x)
{
	if (dp[y][x] != 0)
	{
		return dp[y][x];
	}

	int& ret = dp[y][x];
	ret = 1;

	for (int i = 0; i < 4; i++)
	{
		ny = dy[i] + y;
		nx = dx[i] + x;

		if (ny < 0 || ny >= n || nx < 0 || nx >= n)
		{
			continue;
		}

		if (a[ny][nx] > a[y][x])
		{
			ret = max(ret, dfs(ny, nx) + 1);
		}
	}

	return ret;
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			max_cnt = max(max_cnt, dfs(i, j));
		}
	}

	cout << max_cnt << '\n';

	return 0;
}