#include <bits/stdc++.h>
using namespace std;

int n, num, dp[1000001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		dp[num] = dp[num - 1] + 1;
	}

	cout << n - *max_element(dp + 1, dp + n + 1) << '\n';

	return 0;
}