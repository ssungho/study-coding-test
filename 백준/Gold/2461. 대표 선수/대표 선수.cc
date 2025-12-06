#include <bits/stdc++.h>
using namespace std;

int n, m, val, result = INT_MAX;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
		}
		sort(v[i].begin(), v[i].end());
	}

	vector<int> cur_indices(n, 0);
	while (true)
	{
		int min_index = -1;
		int min_value = INT_MAX;
		int max_value = 0;

		for (int i = 0; i < n; i++)
		{
			int cur_value = v[i][cur_indices[i]];
			if (cur_value < min_value)
			{
				min_value = cur_value;
				min_index = i;
			}
			max_value = max(max_value, cur_value);
		}

		result = min(result, max_value - min_value);
		cur_indices[min_index]++;

		if (cur_indices[min_index] == m)
		{
			break;
		}
	}

	cout << result << '\n';

	return 0;
}