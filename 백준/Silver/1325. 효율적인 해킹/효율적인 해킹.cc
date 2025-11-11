#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, max_cnt;
vector<int> result;
vector<vector<int>> graph;
bool visited[10001];

int dfs(int node)
{
	visited[node] = true;
	
	int cnt = 1;
	for (int i : graph[node])
	{
		if (visited[i])
		{
			continue;
		}
		cnt += dfs(i);
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
		
		int cnt = dfs(i);
		if (max_cnt < cnt)
		{
			result.clear();
			result.push_back(i);
			max_cnt = cnt;
		}
		else if (max_cnt == cnt)
		{
			result.push_back(i);
		}
	}

	sort(result.begin(), result.end());

	for (int i : result)
	{
		cout << i << ' ';
	}
	cout << '\n';

	return 0;
}