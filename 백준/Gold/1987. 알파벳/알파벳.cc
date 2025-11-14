#include <bits/stdc++.h>
using namespace std;

const int dy[4]{-1, 0, 1, 0}, dx[4]{0, 1, 0, -1};
int r, c, result, a[21][21];
bool visited[26];

void go(int y, int x, int cnt)
{
	visited[a[y][x]] = true;
	result = max(result, cnt);
	
	for (int i = 0; i < 4; i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;

		if (ny < 0 || ny >= r || nx < 0 | nx >= c)
		{
			continue;
		}
		if (visited[a[ny][nx]])
		{
			continue;
		}

		go(ny, nx, cnt + 1);
		visited[a[ny][nx]] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		string row;
		cin >> row;
		for (int j = 0; j < c; j++)
		{
			a[i][j] = int(row[j] - 'A');
		}
	}

	go(0, 0, 1);

	cout << result << '\n';

	return 0;
}