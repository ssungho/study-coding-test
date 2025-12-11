#include <bits/stdc++.h>
using namespace std;

const int dy[4]{-1, 0, 1, 0}, dx[4]{0, 1, 0, -1};
int n, m, empty_cnt, result, a[51][51];
bool visited[51][51];
vector<pair<int, int>> virus_pos;
vector<int> active_pos;

int bfs()
{
	int time = 0;
	int visited_cnt = 0;
	memset(visited, 0, sizeof(visited));
	queue<pair<pair<int, int>, int>> q;
	for (int index : active_pos)
	{
		q.push({virus_pos[index], 0});
		visited[virus_pos[index].first][virus_pos[index].second] = true;
	}

	while (q.size())
	{
		int cur_y = q.front().first.first;
		int cur_x = q.front().first.second;
		int cur_time = q.front().second;
		q.pop();

		if (cur_time >= result)
		{
			break;
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int ny = cur_y + dy[dir];
			int nx = cur_x + dx[dir];

			if (ny < 1 || ny > n || nx < 1 || nx > n)
			{
				continue;
			}
			if (visited[ny][nx] || a[ny][nx] == 1)
			{
				continue;
			}

			q.push({{ny, nx}, cur_time + 1});
			visited[ny][nx] = true;

			if (a[ny][nx] == 0)
			{
				visited_cnt++;
				time = cur_time + 1;
			}
		}
	}

	if (visited_cnt != empty_cnt)
	{
		time = INT_MAX;
	}

	return time;
}

void go(int here, int cnt)
{
	if (cnt == m)
	{
		result = min(result, bfs());
		return;
	}

	for (int i = here; i < (int)virus_pos.size(); i++)
	{
		active_pos.push_back(i);
		go(i + 1, cnt + 1);
		active_pos.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 0)
			{
				empty_cnt++;
			}
			else if (a[i][j] == 2)
			{
				virus_pos.push_back({i, j});
			}
		}
	}

	result = INT_MAX;

	go(0, 0);

	if (result == INT_MAX)
	{
		result = -1;
	}

	cout << result << '\n';

	return 0;
}