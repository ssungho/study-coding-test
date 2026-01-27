#include <bits/stdc++.h>
using namespace std;

const int dy[4]{0, -1, 0, 1}, dx[4]{1, 0, -1, 0};
int n, x, y, d, g, result;
bool visited[101][101];
vector<int> dirs;

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> d >> g;
		dirs.clear();
		dirs.push_back(d);

		for (int j = 0; j < g; j++)
		{
			for (int k = dirs.size() - 1; k >= 0; k--)
			{
				dirs.push_back((dirs[k] + 1) % 4);
			}
		}

		int cur_y = y;
		int cur_x = x;
		visited[cur_y][cur_x] = true;
		
		for (int dir : dirs)
		{
			cur_y += dy[dir];
			cur_x += dx[dir];
			visited[cur_y][cur_x] = true;
		}
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (visited[i][j] && visited[i + 1][j] && 
				visited[i][j + 1] && visited[i + 1][j + 1])
			{
				result++;
			}
		}
	}

	cout << result << '\n';

	return 0;
}