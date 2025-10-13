#include <bits/stdc++.h>
using namespace std;

int n, m, total, a[101], c[101];
int result = INT_MAX;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		total += c[i];
	}

	vector<int> dp(total + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		for (int j = total; j >= c[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - c[i]] + a[i]);
		}
	}

	for (int i = 0; i <= total; i++)
	{
		if (dp[i] >= m)
		{
			result = min(result, i);
		}
	}

	cout << result << '\n';

	return 0;
}