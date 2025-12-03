#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

const int mod = 1000000, pisano = 1500000;
int dp[pisano + 1];
ull n;

int main(void)
{
	cin >> n;
	n %= pisano;

	dp[1] = 1;
	for (ull i = 2; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	}

	cout << dp[n] << '\n';

	return 0;
}