#include <bits/stdc++.h>
using namespace std;

int n, times[501], dp[501];
vector<vector<int>> needs(501);

int go(int here)
{
	int& ret = dp[here];
	if (ret != -1)
	{
		return ret;
	}

	ret = 0;
	auto& prevs = needs[here];
	for (auto prev : prevs)
	{
		ret = max(ret, go(prev));
	}

	ret += times[here];

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> times[i];
		while (true)
		{
			int prev;
			cin >> prev;
			if (prev == -1)
			{
				break;
			}
			needs[i].push_back(prev);
		}
	}

	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= n; i++)
	{
		cout << go(i) << '\n';
	}

	return 0;
}