#include <bits/stdc++.h>
using namespace std;

int n, m, l, r, result;
bool visited[501];

void dfs(int here, const vector<vector<int>>& list, int& cnt)
{
	visited[here] = true;
	for (int next : list[here])
	{
		if (!visited[next])
		{
			cnt++;
			dfs(next, list, cnt);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	vector<vector<int>> greater_list(n + 1);
	vector<vector<int>> less_list(n + 1);
	
	for (int i = 0; i < m; i++) 
	{
		cin >> l >> r;
		greater_list[l].push_back(r);
		less_list[r].push_back(l);
	}

	for (int i = 1; i <= n; i++) 
	{
		int total_cnt = 0;
		memset(visited, 0, sizeof(visited));
		dfs(i, less_list, total_cnt);
		
		memset(visited, 0, sizeof(visited));
		dfs(i, greater_list, total_cnt);

		if (total_cnt == n - 1)
		{
			result++;
		}
	}

	cout << result << '\n';

	return 0;
}