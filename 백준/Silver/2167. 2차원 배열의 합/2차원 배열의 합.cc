#include <bits/stdc++.h>
using namespace std;

int a[301][301], prefix_sum[301][301];
int n, m, k;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		prefix_sum[i][0] = prefix_sum[i - 1][m];
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			prefix_sum[i][j] = a[i][j] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
		}
	}

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int sum, y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		sum = prefix_sum[y2][x2] - prefix_sum[y1 - 1][x2] - prefix_sum[y2][x1 - 1] + prefix_sum[y1 - 1][x1 - 1];
		cout << sum << '\n';
	}

	return 0;
}