#include <bits/stdc++.h>
using namespace std;

const int dy[4]{-1, 0, 1, 0}, dx[4]{0, 1, 0, -1};
int result;
char a[5][5];
bool visited[5][5];
string row;
vector<pair<int, int>> selected;

int bfs()
{
	queue<pair<int, int>> q;
	q.push(selected.front());
	visited[selected.front().first][selected.front().second] = true;

	int cnt = 0;
	while (!q.empty())
	{
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();
		cnt++;

		for (int dir = 0; dir < 4; dir++)
		{
			int ny = cur_y + dy[dir];
			int nx = cur_x + dx[dir];

			if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
			{
				continue;
			}
			if (visited[ny][nx] == true)
			{
				continue;
			}

			q.push({ny, nx});
			visited[ny][nx] = true;
		}
	}

	return cnt == 7;
}

void go(int index)
{
	if (selected.size() == 7)
	{
		memset(visited, true, sizeof(visited));
		int s_cnt = 0;

		for (auto& pos : selected)
		{
			s_cnt += (a[pos.first][pos.second] == 'S');
			visited[pos.first][pos.second] = false;
		}

		if (s_cnt >= 4)
		{
			result += bfs();
		}
		
		return;
	}

	for (int i = index; i < 25; i++)
	{
		selected.push_back({i / 5, i % 5});
		go(i + 1);
		selected.pop_back();
	}
}

int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		cin >> row;
		for (int j = 0; j < 5; j++)
		{
			a[i][j] = row[j];
		}
	}

	selected.reserve(25);
	go(0);
	cout << result << '\n';

	return 0;
}