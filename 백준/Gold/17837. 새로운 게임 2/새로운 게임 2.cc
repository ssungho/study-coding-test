#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct piece
{
	int y, x, dir;
};

const int dy[4]{0, 0, -1, 1};
const int dx[4]{1, -1, 0, 0};
pair<int, vector<int>> map[13][13]{};
piece pieces[11]{};
int n, k;

int main(void)
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j].first;
		}
	}

	for (int i = 1; i <= k; i++)
	{
		cin >> pieces[i].y >> pieces[i].x >> pieces[i].dir;
		map[pieces[i].y][pieces[i].x].second.push_back(i);
	}

	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			auto& p = pieces[j];
			int ny = p.y + dy[p.dir - 1];
			int nx = p.x + dx[p.dir - 1];

			if (0 >= ny || ny > n || 0 >= nx || nx > n || map[ny][nx].first == 2)
			{
				if (p.dir % 2)
				{
					p.dir++;
				}
				else
				{
					p.dir--;
				}
				ny = p.y + dy[p.dir - 1];
				nx = p.x + dx[p.dir - 1];

				if (0 >= ny || ny > n || 0 >= nx || nx > n || map[ny][nx].first == 2)
				{
					continue;
				}
			}

			if (0 < ny && ny <= n && 0 < nx && nx <= n)
			{
				auto& next = map[ny][nx];
				auto& current = map[p.y][p.x];

				if (next.first == 0)
				{
					int index = 0;
					while (current.second[index] != j)
					{
						index++;
					}

					int size = current.second.size();

					for (int l = index; l < size; l++)
					{
						next.second.push_back(current.second[l]);
						pieces[current.second[l]].y = ny;
						pieces[current.second[l]].x = nx;
					}

					while (current.second.size() != index)
					{
						current.second.pop_back();
					}

					if (next.second.size() >= 4)
					{
						cout << i << '\n';
						return 0;
					}
				}
				else if (next.first == 1)
				{
					int index = 0;
					while (current.second[index] != j)
					{
						index++;
					}

					vector<int> temp;

					int size = current.second.size();
					for (int l = index; l < size; l++)
					{
						temp.push_back(current.second[l]);
					}

					while (temp.size())
					{
						next.second.push_back(temp.back());
						pieces[temp.back()].y = ny;
						pieces[temp.back()].x = nx;
						temp.pop_back();
					}

					while (current.second.size() != index)
					{
						current.second.pop_back();
					}

					if (next.second.size() >= 4)
					{
						cout << i << '\n';
						return 0;
					}
				}
			}
		}
	}

	cout << -1 << '\n';

	return 0;
}