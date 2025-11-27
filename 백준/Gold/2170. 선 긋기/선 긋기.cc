#include <bits/stdc++.h>
using namespace std;

int n, result;
pair<int, int> a[1000000];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}

	sort(a, a + n);
	pair<int, int> prev = a[0];
	
	for (int i = 1; i < n; i++)
	{
		pair<int, int>& cur = a[i];

		if (cur.first >= prev.second)
		{
			result += (prev.second - prev.first);
			prev = cur;
		}
		else
		{
			prev.first = min(prev.first, cur.first);
			prev.second = max(prev.second, cur.second);
		}
	}

	result +=(prev.second - prev.first);
	cout << result << '\n';

	return 0;
}