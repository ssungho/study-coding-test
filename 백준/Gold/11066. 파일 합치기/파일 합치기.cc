#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		vector<int> costs(n + 1, 0);
		vector<int> sum(n + 1, 0);

		for (int i = 1; i <= n; i++)
		{
			cin >> costs[i];
			sum[i] = sum[i - 1] + costs[i];
		}

		vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));

		for (int i = 1; i <= n; i++)
		{
			dp[i][i] = 0;
		}

		for (int i = 1; i < n; i++)
		{
			for (int left = 1; left <= n - i; left++)
			{
				int right = left + i;
				for (int mid = left; mid < right; mid++)
				{
					int new_value = dp[left][mid] + dp[mid + 1][right] + sum[right] - sum[left - 1];
					dp[left][right] = min(dp[left][right], new_value);
				}
			}
		}

		cout << dp[1][n] << '\n';
	}

	return 0;
}