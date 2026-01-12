#include <bits/stdc++.h>
using namespace std;

const int dy[4]{0, -1, 0, 1}, dx[4]{-1, 0, 1, 0};
int n, m, area_max, area_remove_wall, id, a[50][50];
int visited[50][50];
vector<int> areas(1, -1);

void bfs(int start_y, int start_x)
{
	int area = 0;
	queue<pair<int, int>> q;
	q.push({start_y, start_x});
	visited[start_y][start_x] = id;

	while (!q.empty())
	{
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		area++;
		q.pop();

		int dir_mask = a[cur_y][cur_x];
		for (int dir = 0; dir < 4; dir++)
		{
			if (dir_mask & (1 << dir))
			{
				continue;
			}

			int ny = cur_y + dy[dir];
			int nx = cur_x + dx[dir];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] != 0)
			{
				continue;
			}

			q.push({ny, nx});
			visited[ny][nx] = id;
		}
	}

	areas.push_back(area);
	area_max = max(area_max, area);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] == 0)
			{
				id++;
				bfs(i, j);
			}
		}
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			for (int dir = 2; dir < 4; dir++)
			{
				if (a[y][x] & (1 << dir))
				{
					int ny = y + dy[dir];
					int nx = x + dx[dir];

					if (ny < 0 || ny >= n || nx < 0 || nx >= m)
					{
						continue;
					}

					int cur_id = visited[y][x];
					int next_id = visited[ny][nx];

					if (cur_id != next_id)
					{
						area_remove_wall = max(area_remove_wall, areas[cur_id] + areas[next_id]);
					}
				}
			}
		}
	}

	cout << areas.size() - 1 << '\n'
		 << area_max << '\n'
		 << area_remove_wall << '\n';

	return 0;
}