#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int n, l, r, a[101], dp[101][101][101];

int go(int cur, int left, int right)
{
	if (cur == n)
	{
		if (left == l && right == r)
		{
			return 1;
		}
		return 0;
	}

	int &ret = dp[cur][left][right];
	if (ret != -1)
	{
		return ret;
	}

	ret = 0;
	ret = (ret + go(cur + 1, left + 1, right)) % mod;
	ret = (ret + go(cur + 1, left, right + 1)) % mod;
	ret = (ret + go(cur + 1, left, right) * (long long)(cur - 1)) % mod;

	return ret;
}

int main(void)
{
	cin >> n >> l >> r;
	memset(dp, -1, sizeof(dp));
	cout << go(1, 1, 1) << '\n';
	return 0;
}