#include <bits/stdc++.h>
using namespace std;

struct Pos
{
	int l, r, c;
};

const int dl[2]{-1, 1}, dr[4]{-1, 1, 0, 0}, dc[4]{0, 0, 1, -1};
int l, r, c, nl, nr, nc;
char graph[31][31][31];
bool visited[31][31][31];
Pos s, e;
string row;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{
		cin >> l >> r >> c;
		
		if (l == 0 && r == 0 && c == 0)
		{
			break;
		}

		for (int i = 1; i <= l; i++)
		{
			for (int j = 1; j <= r; j++)
			{
				cin >> row;
				for (int k = 1; k <= c; k++)
				{
					graph[i][j][k] = row[k - 1];
					if (graph[i][j][k] == 'S')
					{
						s = {i, j, k};
					}
					else if (graph[i][j][k] == 'E')
					{
						e = {i, j, k};
					}
				}
			}
		}

		queue<pair<Pos, int>> q;
		memset(visited, 0, sizeof(visited));
		q.push({s, 0});
		visited[s.l][s.r][s.c] = true;
		int min_cnt = -1;

		while (!q.empty())
		{
			Pos cur_pos = q.front().first;
			int cur_cnt = q.front().second;
			q.pop();

			if (cur_pos.l == e.l && cur_pos.r == e.r && cur_pos.c == e.c)
			{
				min_cnt = cur_cnt;
				break;
			}

			for (int i = 0; i < 4; i++)
			{
				nr = dr[i] + cur_pos.r;
				nc = dc[i] + cur_pos.c;

				if (nc < 1 || nc > c || nr < 1 || nr > r)
				{
					continue;
				}
				if (visited[cur_pos.l][nr][nc] || graph[cur_pos.l][nr][nc] == '#')
				{
					continue;
				}

				q.push({{cur_pos.l, nr, nc}, cur_cnt + 1});
				visited[cur_pos.l][nr][nc] = true;
			}
			for (int i = 0; i < 2; i++)
			{
				nl = dl[i] + cur_pos.l;

				if (nl < 1 || nl > l)
				{
					continue;
				}
				if (visited[nl][cur_pos.r][cur_pos.c] || graph[nl][cur_pos.r][cur_pos.c] == '#')
				{
					continue;
				}

				q.push({{nl, cur_pos.r, cur_pos.c}, cur_cnt + 1});
				visited[nl][cur_pos.r][cur_pos.c] = true;
			}
		}

		if (min_cnt == -1)
		{
			printf("Trapped!\n");
		}
		else
		{
			printf("Escaped in %d minute(s).\n", min_cnt);
		}
	}
	return 0;
}