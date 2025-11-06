#include <bits/stdc++.h>

using namespace std;

const int max_size {16};
int n, m, d, answer, a[max_size][max_size], pos[3];
bool visited[16];

bool isEmpty(int copy[max_size][max_size])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (copy[i][j]) return false;
		}
	}
	return true;
}

int simulate()
{
	int kill = 0;
	int copy_a[max_size][max_size];
	memcpy(copy_a, a, sizeof(a));
	pair<int, int> near_list[3];

	while (!isEmpty(copy_a))
	{
		for (int i = 0; i < 3; i++)
		{
			int y = n;
			int x = pos[i];
			int min_dist = d;
			pair<int, int> near{max_size, max_size};

			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < m; k++)
				{
					if (copy_a[j][k] == 0)
					{
						continue;
					}

					int dist = abs(y - j) + abs(x - k);

					if (dist < min_dist)
					{
						near = { j, k };
						min_dist = dist;
					}
					else if (dist == min_dist && near.second > k)
					{
						near = { j, k };
					}
				}
			}

			near_list[i] = near;
		}

		for (int i = 0; i < 3; i++)
		{
			if (near_list[i].first == n && near_list[i].second == n)
			{
				continue;
			}
			int& check = copy_a[near_list[i].first][near_list[i].second];
			if (check == 1)
			{
				kill++;
				check = 0;
			}
		}

		for (int i = n - 1; i > 0; i--)
		{
			memcpy(copy_a[i], copy_a[i - 1], sizeof(int) * max_size);
		}
		for (int i = 0; i < m; i++)
		{
			copy_a[0][i] = 0;
		}
	}

	return kill;
}

void go(int here, int cnt)
{
	if (cnt == 3)
	{
		answer = max(answer, simulate());
		return;
	}

	for (int i = here; i < m; i++)
	{
		if (visited[i])
		{
			continue;
		}

		pos[cnt] = i;
		visited[i] = true;
		go(i, cnt + 1);
		visited[i] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	go(0, 0);
	cout << answer << '\n';

	return 0;
}