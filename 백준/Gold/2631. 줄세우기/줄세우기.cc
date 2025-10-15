#include <bits/stdc++.h>
using namespace std;

int n, a[201], dp[201];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (a[i] > a[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	cout << n - *max_element(dp + 1, dp + n + 1) << '\n';

	return 0;
}