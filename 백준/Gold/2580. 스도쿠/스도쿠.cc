#include <bits/stdc++.h>

using namespace std;

int graph[9][9]{};
bool visited[9][9]{};
vector<pair<int, int>> empty_pos;
bool fin;

bool check(int y, int x, int target)
{

	bool row_visited[10]{};
	bool col_visited[10]{};
	bool area_visited[10]{};

	for (int i = 0; i < 9; i++)
	{
		if (graph[y][i] != 0)
		{
			row_visited[graph[y][i]] = true;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (graph[i][x] != 0)
		{
			col_visited[graph[i][x]] = true;
		}
	}

	int ny = (y / 3) * 3;
	int nx = (x / 3) * 3;

	for (int i = ny; i < ny + 3; i++)
	{
		for (int j = nx; j < nx + 3; j++)
		{
			if (graph[i][j] != 0)
			{
				area_visited[graph[i][j]] = true;
			}
		}
	}

	return !row_visited[target] && !col_visited[target] && !area_visited[target];
}

void backtracking(int index)
{
	if (index == (int)empty_pos.size())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << graph[i][j] << ' ';
			}
			cout << '\n';
		}
		
		fin = true;
		return;
	}

	int y = empty_pos[index].first;
	int x = empty_pos[index].second;

	for (int i = 1; i <= 9; i++)
	{
		if (!visited[y][x] && check(y, x, i))
		{
			visited[y][x] = true;
			graph[y][x] = i;

			backtracking(index + 1);
			graph[y][x] = 0;

			visited[y][x] = false;
		}

		if (fin)
			return;
	}
}

int main(void)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 0)
			{
				empty_pos.push_back({i, j});
			}
		}
	}

	backtracking(0);

	return 0;
}