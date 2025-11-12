#include <bits/stdc++.h>
using namespace std;

const int dy[4]{-1, 0, 1, 0}, dx[4]{0, 1, 0, -1};
int n, l, r, result, a[101][101];
bool visited[101][101];
vector<pair<int, int>> unions;

int go(int y, int x, int &cnt)
{
	int sum = a[y][x];
	visited[y][x] = true;
	unions.push_back({y, x});
	cnt++;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n)
		{
			continue;
		}
		if (visited[ny][nx] == true)
		{
			continue;
		}

		int diff = abs(a[ny][nx] - a[y][x]);
		if (l <= diff && diff <= r)
		{
			sum += go(ny, nx, cnt);
		}
	}

	return sum;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	while (true)
	{
		bool is_move = false;
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visited[i][j])
				{
					continue;
				}

				int cnt = 0;
				int sum = go(i, j, cnt);
				int part = sum / cnt;

				if (is_move == false)
				{
					is_move = (cnt > 1);
				}

				for (auto& p : unions)
				{
					a[p.first][p.second] = part;
				}

				unions.clear();
			}
		}

		if (is_move == false)
		{
			break;
		}

		result++;
	}

	cout << result << '\n';

	return 0;
}