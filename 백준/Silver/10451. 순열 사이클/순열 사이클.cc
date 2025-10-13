#include <bits/stdc++.h>
using namespace std;

int t, n, result, a[1001];
bool visited[1001];

void go(int here)
{
	if (visited[here])
		return;

	visited[here] = true;
	go(a[here]);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	while (t--)
	{
		result = 0;
		memset(a, 0, sizeof(a));
		memset(visited, 0, sizeof(visited));

		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}

		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				go(i);
				result++;
			}
		}

		cout << result << '\n';
	}

	return 0;
}