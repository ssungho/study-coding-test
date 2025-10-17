#include <bits/stdc++.h>

using namespace std;

int n, c, m, sum, from, to, num, result, a[2001];

int main(void)
{
	cin >> n >> c >> m;
	vector<pair<pair<int, int>, int>> v(m);

	for (int i = 0; i < m; i++)
	{
		cin >> v[i].first.first >> v[i].first.second >> v[i].second;
	}

	sort(v.begin(), v.end(), [](auto &a, auto &b)
	{
		if (a.first.second == b.first.second)
			return a.first.first < b.first.first;
		return a.first.second < b.first.second;
	});

	for (int i = 0; i < m; i++)
	{
		from = v[i].first.first;
		to = v[i].first.second;
		num = v[i].second;

		int max_num = 0;
		for (int j = from; j < to; j++)
		{
			max_num = max(max_num, a[j]);
		}

		int take = min(num, c - max_num);
		if (take > 0)
		{
			result += take;
			for (int j = from; j < to; j++)
			{
				a[j] += take;
			}
		}
	}

	cout << result << '\n';
	
	return 0;
}