#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

map<ull, ull> dp;
ull n, p, q;

ull go(ull i) 
{
	if (i == 0) 
	{
		return 1;
	}

	auto iter = dp.find(i);
	if (iter != dp.end()) 
	{
		return (*iter).second;
	}

	return dp[i] = go(i/p) + go(i/q);
}

int main(void)
{
	cin >> n >> p >> q;

	cout << go(n) << '\n';

	return 0;
}