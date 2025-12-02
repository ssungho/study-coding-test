#include <bits/stdc++.h>
using namespace std;

const int min_val = -100000000;
int n, m, a[1001][1001], dp[1001][1001], dp_right[1001][1001], dp_left[1001][1001];

int main(void)
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = min_val;
		}
	}

	dp[1][1] = a[1][1];
	for (int i = 2; i <= m; i++)
	{
		dp[1][i] = dp[1][i - 1] + a[1][i];
	}

	for (int i = 2; i <= n; i++)
	{
		// 왼 -> 오
		dp_right[i][1] = dp[i - 1][1] + a[i][1];
		for (int j = 2; j <= m; j++)
		{
			dp_right[i][j] = max(dp_right[i][j - 1], dp[i - 1][j]) + a[i][j];
		}

		// 오 -> 왼
		dp_left[i][m] = dp[i - 1][m] + a[i][m];
		for (int j = m - 1; j > 0; j--)
		{
			dp_left[i][j] = max(dp_left[i][j + 1], dp[i - 1][j]) + a[i][j];
		}

		// 최종 갱신
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = max(dp_left[i][j], dp_right[i][j]);
		}
	}

	cout << dp[n][m] << '\n';

	return 0;
}