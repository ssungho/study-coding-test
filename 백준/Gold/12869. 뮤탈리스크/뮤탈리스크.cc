#include <bits/stdc++.h>
using namespace std;

const int damages[6][3]
{
	{9, 3, 1},
	{9, 1, 3},
	{3, 9, 1},
	{3, 1, 9},
	{1, 3, 9},
	{1, 9, 3},
};

int n, result, a[3];
bool visited[61][61][61];

struct node
{
	int hp1, hp2, hp3, cnt;
};

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	queue<node> q;
	q.push({a[0], a[1], a[2]});
	visited[a[0]][a[1]][a[2]] = true;

	while (!q.empty())
	{
		node cur = q.front();
		q.pop();

		if (cur.hp1 == 0 && cur.hp2 == 0 && cur.hp3 == 0)
		{
			result = cur.cnt;
			break;
		}

		for (auto damage : damages)
		{
			node next
			{
				max(0, cur.hp1 - damage[0]),
				max(0, cur.hp2 - damage[1]),
				max(0, cur.hp3 - damage[2]),
				cur.cnt + 1
			};

			if (visited[next.hp1][next.hp2][next.hp3] == false)
			{
				visited[next.hp1][next.hp2][next.hp3] = true;
				q.push(next);
			}
		}
	}

	cout << result << '\n';

	return 0;
}