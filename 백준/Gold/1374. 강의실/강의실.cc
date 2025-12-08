#include <bits/stdc++.h>
using namespace std;

int n, temp, result;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	vector<pair<int, int>> v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		// 위치가 중요하지 않음.
		cin >> temp >> v[i].first >> v[i].second;
	}
	sort(v.begin() + 1, v.end());

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++)
	{
		int cur_start = v[i].first;
		int cur_end = v[i].second;

		while (pq.size() && pq.top() <= cur_start)
		{
			pq.pop();
		}

		pq.push(cur_end);
		result = max(result, (int)pq.size());
	}
	
	cout << result << '\n';

	return 0;
}