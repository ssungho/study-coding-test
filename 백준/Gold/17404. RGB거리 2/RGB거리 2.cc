#include <iostream>
#include <climits>

using namespace std;

int n;
int costs[1001][3]{};
int dp[1001][3]{};

int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> costs[i][j];
		}
	}

	int result = INT_MAX;

	for (int i = 0; i < 3; i++)
	{
		dp[1][0] = dp[1][1] = dp[1][2] = 1000;
		dp[1][i] = costs[1][i];

		for (int j = 2; j <= n; j++)
		{
			dp[j][0] = costs[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
			dp[j][1] = costs[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
			dp[j][2] = costs[j][2] + min(dp[j - 1][0], dp[j - 1][1]);
		}

		for (int j = 0; j < 3; j++)
		{
			if (i != j)
			{
				result = min(result, dp[n][j]);
			}
		}
	}

	cout << result << '\n';

	return 0;
}