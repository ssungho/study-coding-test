#include <bits/stdc++.h>

using namespace std;

int n, w, pos[1001][2], dp[1001][1001], path[1001][1001];

int dist(int car, int next, bool is_a)
{
	int y = pos[next][0];
	int x = pos[next][1];

	int prev_y = pos[car][0];
	int prev_x = pos[car][1];

	if (car == 0)
	{
		prev_y = prev_x = ((is_a) ? 1 : n);
	}

	return abs(y - prev_y) + abs(x - prev_x);
}

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
	
	int cost_a = dist(a, next, true) + go(next, b);
	int cost_b = dist(b, next, false) + go(a, next);

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