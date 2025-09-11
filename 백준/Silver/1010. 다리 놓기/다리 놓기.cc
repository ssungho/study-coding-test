#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int dp[31][31]{};

	for (int i = 0; i <= 30; i++)
	{
		dp[i][0] = 1;
		dp[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	int t, n, m;
	cin >> t;

	while (t--)
	{
		cin >> n >> m;
		cout << dp[m][n] << '\n';
	}

	return 0;
}