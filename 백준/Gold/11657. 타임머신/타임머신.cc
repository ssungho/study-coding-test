#include <iostream>
#include <vector> 
#include <climits>

using namespace std;

int n, m;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	vector<vector<int>> graph(n + 1);
	vector<vector<int>> costs(n + 1, vector<int>(n + 1, INT_MAX));

	for (int i = 0; i < m; i ++) 
	{
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back(b);
		costs[a][b] = min(costs[a][b], c);
	}

	for (int i = 1; i <= n; i++) 
	{
		costs[i][i] = 0;
	}

	for (int k = 1; k <= n; k++) 
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (costs[i][k] == INT_MAX || costs[k][j] == INT_MAX) 
				{
					continue;
				}

				costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (costs[1][i] != INT_MAX && costs[i][i] < 0)
		{
			cout << -1 << '\n';
			return 0;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		cout << (costs[1][i] == INT_MAX ? -1 : costs[1][i]) << '\n';
	}

	return 0;
}