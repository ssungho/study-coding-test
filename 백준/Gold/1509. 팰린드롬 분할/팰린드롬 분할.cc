#include <bits/stdc++.h>
using namespace std;

string s;
bool pre_check[2501][2501]; // [start][length]
int len, dp[2501];

int go(int here)
{
	if (here == len)
	{
		return 0;
	}

	int& ret = dp[here];
	if (ret != INT_MAX)
	{
		return ret;
	}

	for (int i = 1; here + i <= len; i++)
	{
		if (pre_check[here][i] == true)
		{
			ret = min(ret, go(here + i) + 1);
		}
	}

	return ret;
}

int main(void)
{
	cin >> s;
	len = (int)s.length();

	for (int i = 0; i < len; i++)
	{
		pre_check[i][1] = true;
	}

	for (int i = 0; i < len - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			pre_check[i][2] = true;
		}
	}

	for (int i = 3; i <= len; i++)
	{
		for (int j = 0; j + i <= len; j++)
		{
			if (s[j] == s[j + i - 1] && pre_check[j + 1][i - 2])
			{
				pre_check[j][i] = true;
			}
		}
	}

	fill(dp, dp + 2501, INT_MAX);
	
	cout << go(0) << '\n';

	return 0;
}