#include <bits/stdc++.h>
using namespace std;

struct node
{
	int y, x, is_fire, cnt;
};

const char FIRE = 'F', WALL = '#', EMPTY = '.', INIT = 'J';
const int dy[4]{-1, 0, 1, 0}, dx[4]{0, 1, 0, -1};
int r, c, move_cnt = -1;
char a[1001][1001];
bool visited[1001][1001][2];
pair<int, int> start_pos;
queue<node> q;
queue<pair<int, int>> fire_pos;

int main(void)
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == FIRE)
			{
				fire_pos.push({i, j});
			}
			else if (a[i][j] == INIT)
			{
				start_pos = {i, j};
				a[i][j] = EMPTY;
			}
		}
	}

	q.push({start_pos.first, start_pos.second, 0, 0});
	visited[start_pos.first][start_pos.second][0] = true;

	while (!fire_pos.empty())
	{
		q.push({fire_pos.front().first, fire_pos.front().second, 1, 0});
		visited[fire_pos.front().first][fire_pos.front().second][1] = true;
		fire_pos.pop();
	}

	while (!q.empty())
	{
		node cur = q.front();
		q.pop();

		if (cur.is_fire == false && visited[cur.y][cur.x][1] == true)
		{
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + cur.y;
			int nx = dx[i] + cur.x;

			if (cur.is_fire == false)
			{
				if (ny < 0 || ny >= r || nx < 0 || nx >= c)
				{
					move_cnt = cur.cnt + 1;
					break;
				}
				if (a[ny][nx] == EMPTY && visited[ny][nx][0] == false && visited[ny][nx][1] == false)
				{
					q.push({ny, nx, cur.is_fire, cur.cnt + 1});
					visited[ny][nx][cur.is_fire] = true;
				}
			}
			else
			{
				if (ny < 0 || ny >= r || nx < 0 || nx >= c)
				{
					continue;
				}
				if (a[ny][nx] != WALL && visited[ny][nx][1] == false)
				{
					q.push({ny, nx, cur.is_fire, cur.cnt + 1});
					visited[ny][nx][cur.is_fire] = true;
				}
			}
		}

		if (move_cnt != -1)
		{
			break;
		}
	}

	if (move_cnt == -1)
	{
		cout << "IMPOSSIBLE\n";
	}
	else
	{
		cout << move_cnt << '\n';
	}

	return 0;
}