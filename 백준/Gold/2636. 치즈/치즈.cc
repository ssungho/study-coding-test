#include <bits/stdc++.h>
using namespace std;

const int dy[4]{-1, 0, 1, 0}, dx[4]{0, 1, 0, -1};
int n, m, result, prev_melt, a[101][101];
bool visited[101][101];

void dfs(int y, int x, bool from_cheese)
{
	visited[y][x] = true;

	if (from_cheese)
	{
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;

		if (ny < 0 || ny >= n || nx < 0 || nx >= m)
		{
			continue;
		}
		if (visited[ny][nx] == true)
		{
			continue;
		}

		dfs(ny, nx, a[ny][nx]);
	}
}

int melt()
{
	int melt_cnt = 0;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] == true && a[i][j] == 1)
			{
				a[i][j] = 0;
				melt_cnt++;
			}
		}
	}

	return melt_cnt;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	while (true)
	{
		memset(visited, 0, sizeof(visited));
		dfs(0, 0, a[0][0]);
		int melt_cnt = melt();

		if (melt_cnt == 0)
		{
			cout << result << '\n'
				 << prev_melt << '\n';
			break;
		}
		
		prev_melt = melt_cnt;
		result++;
	}

	return 0;
}