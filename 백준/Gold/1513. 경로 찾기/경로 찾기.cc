#include <bits/stdc++.h>

using namespace std;

constexpr int mod{1000007};

int dp[51][51][51][51]{};
int game[51][51]{};
int n, m, c;

int Search(int y, int x, int count, int prev) 
{
	if (y > n || x > m) 
	{
		return 0;
	}

	if (y == n && x == m) 
	{
		if (count == 0 && game[y][x] == 0)
		{
			return 1;
		}

		if (count == 1 && game[y][x] > prev)
		{
			return 1;
		}

		return 0;
	}

	int& result = dp[y][x][count][prev];

	if (result != -1)
		return result;

	result = 0;

	if (game[y][x] == 0)
	{
		result = (Search(y + 1, x, count, prev) + Search(y, x + 1, count, prev)) % mod;
	}
	else if (game[y][x] > prev)
	{
		result = (Search(y + 1, x, count - 1, game[y][x]) + Search(y, x + 1, count - 1, game[y][x])) % mod;
	}

	return result;
}

int main(void)
{
	cin >> n >> m >> c;

	for (int i = 1; i <= c; i++) 
	{
		int y, x;
		cin >> y >> x;
		game[y][x] = i;
	}

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i <= c; i++) 
	{
		cout << Search(1, 1, i, 0) << '\n';
	}

	return 0;
}