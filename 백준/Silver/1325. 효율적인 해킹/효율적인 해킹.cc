#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, cnt, max_cnt;
bool visited[10001];
vector<vector<int>> graph;
vector<int> answer;

int go(int x)
{
	int cnt = 1;
	visited[x] = true;

	for (int next : graph[x])
	{
		if (visited[next] == false)
		{
			cnt += go(next);
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
	graph.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		memset(visited, 0, sizeof(visited));
		cnt = go(i);

		if (cnt > max_cnt)
		{
			max_cnt = cnt;
			answer.clear();
			answer.push_back(i);
		}
		else if (cnt == max_cnt)
		{
			answer.push_back(i);
		}
	}

	for (int i : answer)
	{
		cout << i << ' ';
	}

	return 0;
}