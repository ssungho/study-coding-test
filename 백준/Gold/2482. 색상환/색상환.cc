#include <bits/stdc++.h>
using namespace std;

constexpr int mod{1000000003};
int n, k, result, dp[1001][1001];

int main(void)
{
	cin >> n >> k;
	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = 1;
	}
	dp[1][1] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % mod;
		}
	}

	result = (dp[n - 1][k] + dp[n - 3][k - 1]) % mod;
	cout << result << '\n';

	return 0;
}