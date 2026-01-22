#include <bits/stdc++.h>
using namespace std;

int n, t, w, v, dp[10001];
pair<int, int> a[101];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> t;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}

	for (int i = 1; i <= n; i++)
	{
		w = a[i].first;
		v = a[i].second;
		for (int j = t; j >= w; j--)
		{
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}

	cout << dp[t] << '\n';
	return 0;
}