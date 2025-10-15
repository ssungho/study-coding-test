#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000000;
int n, answer, dp[201][10][1 << 10];

int go(int here, int next, long long mask)
{
	if (here == n)
	{
		for (int i = 0; i <= 9; i++)
		{
			if (!(mask & (1 << i)))
				return 0;
		}
		return 1;
	}

	int& ret = dp[here][next][mask];
	if (ret != -1)
		return ret;

	ret = 0;
	if (next - 1 >= 0)
		ret = (ret + go(here + 1, next - 1, (mask | (1 << (next - 1))))) % mod;
	if (next + 1 <= 9)
		ret = (ret + go(here + 1, next + 1, (mask | (1 << (next + 1))))) % mod;

	return ret;
}

int main(void)
{
	cin >> n;
	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= 9; i++)
	{
		answer += go(1, i, (1 << i));
		answer %= mod;
	}

	cout << answer << '\n';

	return 0;
}