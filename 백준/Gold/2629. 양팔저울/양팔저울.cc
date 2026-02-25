#include <bits/stdc++.h>
using namespace std;

int n, m, a[30], beads[7];
bool dp[31][40001];

void go(int here, int weight)
{
	if (here > n || dp[here][weight])
	{
		return;
	}

	dp[here][weight] = true;

	go(here + 1, weight);
	go(here + 1, weight + a[here]);
	go(here + 1, weight - a[here]);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> beads[i];
	}

	go(0, 0);

	for (int i = 0; i < m; i++)
	{
		if (dp[n][beads[i]])
		{
			cout << "Y ";
		}
		else
		{
			cout << "N ";
		}
	}
	cout << '\n';

	return 0;
}