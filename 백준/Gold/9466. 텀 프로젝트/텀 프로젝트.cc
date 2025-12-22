#include <bits/stdc++.h>
using namespace std;

int t, n, a[100001], visited[100001];

int go(int here)
{
	// 탐색 시작.
	visited[here] = 1;
	int next = a[here];
	int cnt = 0;

	if (visited[next] == 0)
	{
		cnt += go(next);
	}
	else if (visited[next] == 1)
	{
		cnt = 1;
		while (next != here)
		{
			cnt++;
			next = a[next];
		}
	}

	// 탐색 종료
	visited[here] = 2;
	return cnt;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--)
	{
		memset(visited, 0, sizeof(visited));

		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (visited[i] == 0)
			{
				cnt += go(i);
			}
		}

		cout << n - cnt << '\n';
	}

	return 0;
}