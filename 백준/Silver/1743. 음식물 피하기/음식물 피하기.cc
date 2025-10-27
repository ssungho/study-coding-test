#include <bits/stdc++.h>
using namespace std;

const int dy[4]{-1, 0, 1, 0}, dx[4]{0, 1, 0, -1};
int n, m, k, r, c, max_size;
bool a[101][101], visited[101][101];

int go(int y, int x)
{
	if (visited[y][x]) 
		return 0;

	visited[y][x] = true;
	int cnt = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 1 || ny > n || nx < 1 || nx > m)
			continue;
		if (!a[ny][nx] || visited[ny][nx])
			continue;

		cnt += go(ny, nx);
	}

	return cnt;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> r >> c;
		a[r][c] = true;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] && !visited[i][j])
			{
				max_size = max(max_size, go(i, j));
			}
		}
	}

	cout << max_size << '\n';

	return 0;
}