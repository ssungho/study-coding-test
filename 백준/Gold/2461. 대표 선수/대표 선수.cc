#include <bits/stdc++.h>
using namespace std;

// value, class, index
using pi_pii = pair<int, pair<int, int>>;
int n, m, max_value, result = INT_MAX;

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
		max_value = max(max_value, v[i][0]);
	}

	priority_queue<pi_pii, vector<pi_pii>, greater<pi_pii>> pq;
	for (int i = 0; i < n; i++)
	{
		pq.push({v[i][0], {i, 0}});
	}

	while (true)
	{
		int cur_value = pq.top().first;
		int cur_class = pq.top().second.first;
		int cur_index = pq.top().second.second;
		pq.pop();

		result = min(result, max_value - cur_value);

		if (result == 0 || cur_index + 1 == m)
		{
			break;
		}

		pq.push({v[cur_class][cur_index + 1], {cur_class, cur_index + 1}});
		max_value = max(max_value, v[cur_class][cur_index + 1]);
	}

	cout << result << '\n';

	return 0;
}