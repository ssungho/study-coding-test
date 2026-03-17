#include <bits/stdc++.h>
using namespace std;

const int dy[]{-1, 0, 1, 0}, dx[]{0, 1, 0, -1};
int n, m, result, a[101][101];
bool visited[101][101];
string row;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> row;
		for (int j = 1; j <= m; j++)
		{
			a[i][j] = row[j - 1];
		}
	}

	queue<pair<int, pair<int, int>>> q;
	q.push({1, {1, 1}});
	visited[1][1] = true;

	while (!q.empty())
	{
		int cur_cnt = q.front().first;
		int cur_y = q.front().second.first;
		int cur_x = q.front().second.second;
		q.pop();

		if (cur_y == n && cur_x == m)
		{
			result = cur_cnt;
			break;
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int ny = dy[dir] + cur_y;
			int nx = dx[dir] + cur_x;

			if (ny < 1 || ny > n || nx < 1 || nx > m)
			{
				continue;
			}
			if (a[ny][nx] == '0' || visited[ny][nx])
			{
				continue;
			}

			q.push({cur_cnt + 1, {ny, nx}});
			visited[ny][nx] = true;
		}
	}

	cout << result << '\n';

	return 0;
}