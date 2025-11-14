#include <bits/stdc++.h>
using namespace std;

const int dy[4]{-1, 0, 1, 0}, dx[4]{0, 1, 0, -1};
int r, c, result;
string row;
char a[1501][1501];
pair<int, int> swan_pos;
queue<pair<int, int>> water_q, next_water_q, swan_q, next_swan_q;
bool water_visited[1501][1501], swan_visited[1501][1501];

bool swan_bfs()
{
	while (!swan_q.empty())
	{
		int cur_y = swan_q.front().first;
		int cur_x = swan_q.front().second;
		swan_q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];
			if (ny < 1 || ny > r || nx < 1 || nx > c || swan_visited[ny][nx])
			{
				continue;
			}

			swan_visited[ny][nx] = true;
			if (a[ny][nx] == 'X')
			{
				next_swan_q.push({ny, nx});
			}
			else if (a[ny][nx] == '.')
			{
				swan_q.push({ny, nx});
			}
			else if (a[ny][nx] == 'L')
			{
				return true;
			}
		}
	}

	return false;
}

void water_bfs()
{
	while (!water_q.empty())
	{
		int cur_y = water_q.front().first;
		int cur_x = water_q.front().second;
		water_q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];

			if (ny < 1 || ny > r || nx < 1 || nx > c || water_visited[ny][nx])
			{
				continue;
			}
			
			if (a[ny][nx] == 'X')
			{
				water_visited[ny][nx] = true;
				next_water_q.push({ny, nx});
				a[ny][nx] = '.';
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> r >> c;
	for (int i = 1; i <= r; i++)
	{
		cin >> row;
		for (int j = 1; j <= c; j++)
		{
			a[i][j] = row[j - 1];
			if (a[i][j] == 'L')
			{
				swan_pos = {i, j};
			}
			if (a[i][j] == 'L' || a[i][j] == '.')
			{
				water_q.push({i, j});
				water_visited[i][j] = true;
			}
		}
	}

	swan_q.push(swan_pos);
	swan_visited[swan_pos.first][swan_pos.second] = true;

	while (!swan_bfs())
	{
		result++;
		water_bfs();

		swan_q.swap(next_swan_q);
		water_q.swap(next_water_q);

		queue<pair<int, int>>().swap(next_swan_q);
		queue<pair<int, int>>().swap(next_water_q);
	}

	cout << result << '\n';

	return 0;
}