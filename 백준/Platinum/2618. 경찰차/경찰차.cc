#include <bits/stdc++.h>

using namespace std;

int n, w, pos[1001][2], dp[1001][1001], path[1001][1001];

int go(int a, int b)
{
	int next = max(a, b) + 1;
	if (next > w)
	{
		return 0;
	}

	int& ret = dp[a][b];
	if (ret != -1)
	{
		return ret;
	}

	int cost_a;
	if (a == 0)
	{
		cost_a = abs(1 - pos[next][0]) + abs(1 - pos[next][1]);
	}
	else
	{
		cost_a = abs(pos[a][0] - pos[next][0]) + abs(pos[a][1] - pos[next][1]);
	}
	cost_a += go(next, b);

	int cost_b;
	if (b == 0)
	{
		cost_b = abs(n - pos[next][0]) + abs(n - pos[next][1]);
	}
	else
	{
		cost_b = abs(pos[b][0] - pos[next][0]) + abs(pos[b][1] - pos[next][1]);
	}
	cost_b += go(a, next);

	if (cost_a < cost_b)
	{
		path[a][b] = 1;
		ret = cost_a;
	}
	else
	{
		path[a][b] = 2;
		ret = cost_b;
	}

	return ret;
}

int main(void)
{
	cin >> n >> w;
	for (int i = 1; i <= w; i++)
	{
		cin >> pos[i][0] >> pos[i][1];
	}

	memset(dp, -1, sizeof(dp));
	cout << go(0, 0) << '\n';

	int a = 0, b = 0;
	for (int i = 1; i <= w; i++)
	{
		cout << path[a][b] << '\n';

		(path[a][b] == 1) ? a = i : b = i;
	}

	return 0;
}