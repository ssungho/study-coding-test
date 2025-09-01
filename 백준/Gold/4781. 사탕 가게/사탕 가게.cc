#include <bits/stdc++.h>

using namespace std;

int n;
float m;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (true)
	{
		cin >> n >> m;
		int int_m = round(m * 100.f);

		if (n == 0 && int_m == 0)
			break;

		vector<pair<int, int>> candies(n + 1);
		vector<int> dp(int_m + 1, 0);

		for (int i = 1; i <= n; i++)
		{
			int cal;
			float money;
			cin >> cal >> money;
			money = round(money * 100.f);
			candies[i] = { cal, money };
		}

		for (int i = 1; i <= n; i++)
		{
			int cal = candies[i].first;
			int money = candies[i].second;

			for (int k = money; k <= int_m; k++)
			{
				dp[k] = max(dp[k], dp[k - money] + cal);
			}
		}

		cout << dp[int_m] << '\n';
	}

	return 0;
}