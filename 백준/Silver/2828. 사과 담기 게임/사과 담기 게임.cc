#include <bits/stdc++.h>
using namespace std;

const int dx[2]{-1, 1};
int n, m, j, a[21], result, pos_l = 1;
bool visited[21];

int bfs(int target_pos)
{
	int cnt = -1;
	queue<pair<int, int>> q;
	q.push({0, pos_l});
	visited[pos_l] = true;

	while (!q.empty())
	{
		int cur_cnt = q.front().first;
		int cur_pos = q.front().second;
		q.pop();

		for (int i = 0; i < m; i++)
		{
			if (target_pos == cur_pos + i)
			{
				pos_l = cur_pos;
				cnt = cur_cnt;
				return cnt;
			}
		}

		for (int i = 0; i < 2; i++)
		{
			int new_pos = cur_pos + dx[i];
			if (0 < new_pos && new_pos <= n && visited[new_pos] == false)
			{
				q.push({cur_cnt + 1, new_pos});
				visited[new_pos] = true;
			}
		}
	}

	return cnt;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	cin >> j;
	for (int i = 0; i < j; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < j; i++)
	{
		memset(visited, 0, sizeof(visited));
		result += bfs(a[i]);
	}

	cout << result << '\n';

	return 0;
}