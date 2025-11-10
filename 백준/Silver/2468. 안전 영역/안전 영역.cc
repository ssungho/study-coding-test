#include <bits/stdc++.h>
using namespace std;

const int dy[4]{-1, 0, 1, 0}, dx[4]{0, 1, 0, -1};
int n, min_height, max_height, result, graph[100][100];
bool visited[100][100];

void dfs(int y, int x, int h)
{
	visited[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n)
		{
			continue;
		}
		if (graph[ny][nx] <= h || visited[ny][nx] == true)
		{
			continue;
		}

		dfs(ny, nx, h);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	min_height = 100;
	max_height = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
			min_height = min(min_height, graph[i][j]);
			max_height = max(max_height, graph[i][j]);
		}
	}

	for (int h = min_height; h <= max_height; h++)
	{
		int cur_cnt = 0;
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visited[i][j] == false && graph[i][j] > h)
				{
					dfs(i, j, h);
					cur_cnt++;
				}
			}
		}

		result = max(result, cur_cnt);
	}

	if (min_height == max_height) 
	{
		result = 1;
	}
	cout << result << '\n';

	return 0;
}