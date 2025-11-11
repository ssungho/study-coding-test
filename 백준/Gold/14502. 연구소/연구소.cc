#include <bits/stdc++.h>
using namespace std;

const int dy[4]{-1, 0, 1, 0}, dx[4]{0, 1, 0, -1};
int n, m, total, ny, nx, result, a[8][8];
vector<pair<int, int>> virus_pos;
vector<pair<int, int>> safe_pos;
bool visited[8][8];

int bfs()
{
	int ret = (int)safe_pos.size() + (int)virus_pos.size() - 3;
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> q;
	for (auto& pos : virus_pos)
	{
		q.push(pos);
		visited[pos.first][pos.second] = true;
	}

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		ret--;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			ny = y + dy[i];
			nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;
			if (a[ny][nx] != 0 || visited[ny][nx] == true)
				continue;

			q.push({ny, nx});
			visited[ny][nx] = true;
		}
	}

	return ret;
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
			if (a[i][j] == 0)
			{
				safe_pos.push_back({i, j});
			}
			else if (a[i][j] == 2)
			{
				virus_pos.push_back({i, j});
			}
		}
	}

	total = n * m;
	int safe_cnt = (int)safe_pos.size();

	for (int i = 0; i < safe_cnt - 2; i++)
	{
		for (int j = i + 1; j < safe_cnt - 1; j++)
		{
			for (int k = j + 1; k < safe_cnt; k++)
			{
				a[safe_pos[i].first][safe_pos[i].second] = 1;
				a[safe_pos[j].first][safe_pos[j].second] = 1;
				a[safe_pos[k].first][safe_pos[k].second] = 1;

				result = max(result, bfs());

				a[safe_pos[i].first][safe_pos[i].second] = 0;
				a[safe_pos[j].first][safe_pos[j].second] = 0;
				a[safe_pos[k].first][safe_pos[k].second] = 0;
			}
		}
	}

	cout << result << '\n';

	return 0;
}