#include <bits/stdc++.h>
using namespace std;

int n, k, a[100001], prev_pos[100001];
bool visited[100001];

void bfs()
{
	queue<int> q;
	q.push(n);
	visited[n] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == k)
		{
			break;
		}

		for (auto next : {cur - 1, cur + 1, cur * 2})
		{
			if (0 <= next && next <= 100000 && visited[next] == false)
			{
				q.push(next);
				visited[next] = true;
				prev_pos[next] = cur;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	memset(prev_pos, -1, sizeof(prev_pos));
	bfs();

	stack<int> path;
	int last = k;
	while (last != -1)
	{
		path.push(last);
		last = prev_pos[last];
	}

	cout << path.size() - 1 << '\n';
	while (!path.empty())
	{
		cout << path.top() << ' ';
		path.pop();
	}
	cout << '\n';

	return 0;
}