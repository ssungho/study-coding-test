#include <bits/stdc++.h>
using namespace std;

const int mod{1000000};
string str;
int len, dp[5001];

int main(void)
{
	cin >> str;
	str = "0" + str;
	len = (int)str.size() - 1;

	dp[0] = 1;
	dp[1] = 1;

	if (str[1] == '0')
    {
		dp[1] = 0;
	}

	for (int i = 2; i <= len; i++)
	{
		int curr = str[i] - '0';
		int prev = str[i - 1] - '0';
		int temp = prev * 10 + curr;

		if (curr > 0)
		{
			dp[i] = (dp[i] + dp[i - 1]) % mod;
		}

		if (10 <= temp && temp <= 26)
		{
			dp[i] = (dp[i] + dp[i - 2]) % mod;
		}
	}

	cout << dp[len] << '\n';

	return 0;
}