#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, target, result;
bool visited[100];

int dfs(const vector<vector<int>>& v, int current)
{
	int cnt = 1;
	visited[current] = true;
	for (auto next : v[current])
	{
		if (visited[next] == false)
		{
			cnt += dfs(v, next);
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
	vector<vector<int>> greater(n + 1);
	vector<vector<int>> less(n + 1);

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		greater[b].push_back(a);
		less[a].push_back(b);
	}

	target = (n + 1) / 2;

	for (int i = 1; i <= n; i++)
	{
		memset(visited, 0, sizeof(visited));
		int cnt_less = dfs(less, i);

		memset(visited, 0, sizeof(visited));
		int cnt_greater = dfs(greater, i);

		if (target < cnt_less || target < cnt_greater)
		{
			result++;
		}
	}

	cout << result << '\n';

	return 0;
}