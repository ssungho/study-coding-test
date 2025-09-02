#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dir_size{8};
const int dy[dir_size]{-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[dir_size]{0, 1, 1, 1, 0, -1, -1, -1};

int a[11][11]{};
int food[11][11]{};
int n, m, k;
vector<int> trees[11][11];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			food[i][j] = 5;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		trees[x][y].push_back(z);
	}

	for (int i = 0; i < k; i++)
	{
		for (int r = 1; r <= n; r++)
		{
			for (int c = 1; c <= n; c++)
			{
				if (trees[r][c].empty())
				{
					continue;
				}

				sort(trees[r][c].begin(), trees[r][c].end());

				vector<int> new_trees;
				vector<int> dead_trees;

				for (auto age : trees[r][c])
				{
					if (food[r][c] >= age)
					{
						food[r][c] -= age;
						new_trees.push_back(age + 1);
					}
					else
					{
						dead_trees.push_back(age);
					}
				}

				trees[r][c] = move(new_trees);

				for (auto age : dead_trees)
				{
					food[r][c] += (age / 2);
				}
			}
		}

		for (int r = 1; r <= n; r++)
		{
			for (int c = 1; c <= n; c++)
			{
				for (auto age : trees[r][c])
				{
					if (age % 5 == 0)
					{
						for (int dir = 0; dir < dir_size; dir++)
						{
							int ny = r + dy[dir];
							int nx = c + dx[dir];

							if (1 <= ny && ny <= n && 1 <= nx && nx <= n)
							{
								trees[ny][nx].push_back(1);
							}
						}
					}
				}

				food[r][c] += a[r][c];
			}
		}
	}

	int count_trees = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			count_trees += trees[i][j].size();
		}
	}

	cout << count_trees << '\n';

	return 0;
}