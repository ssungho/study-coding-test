#include <iostream>
#include <queue>

using namespace std;

int map[1000][1000];
bool visited[1000][1000];
int dist[1000][1000];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	pair<int, int> target;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;
			map[i][j] = temp;

			if (temp == 2)
				target = make_pair(i, j);
			dist[i][j] = 0;
		}
	}

	queue<pair<int, int>> q;
	q.push(target);
	while (!q.empty())
	{
		pair<int, int> current = q.front();
		visited[current.first][current.second] = true;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = current.first + dx[i];
			int ny = current.second + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m && visited[nx][ny] == false)
			{
				if (map[nx][ny] == 0)
					dist[nx][ny] = 0;
				else
				{
					dist[nx][ny] = dist[current.first][current.second] + 1;
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 1 && dist[i][j] == 0)
				cout << -1 << " ";
			else
				cout << dist[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}