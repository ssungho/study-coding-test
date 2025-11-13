#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> a[100000];

int get_dist(const pair<int, int>& l, const pair<int, int>& r)
{
	int x = l.first - r.first;
	int y = l.second - r.second;
	return x * x + y * y;
}

int go(int l, int r)
{
	if (r - l <= 3)
	{
		int min_dist = INT_MAX;
		for (int i = l; i < r - 1; i++)
		{
			for (int j = i + 1; j < r; j++)
			{
				min_dist = min(min_dist, get_dist(a[i], a[j]));
			}
		}

		sort(a + l, a + r, [](auto& p1, auto& p2)
		{ 
			return p1.second < p2.second; 
		});

		return min_dist;
	}

	int mid = (l + r) / 2;
	int mid_x = a[mid].first;

	int dist = min(go(l, mid), go(mid, r));

	vector<pair<int, int>> v;
	for (int i = l; i < r; i++)
	{
		int x = abs(a[i].first - mid_x);
		if (x < dist)
		{
			v.push_back(a[i]);
		}
	}

	sort(v.begin(), v.end(), [](auto& p1, auto& p2)
	{ 
			return p1.second < p2.second; 
	});

	for (int i = 0; i < (int)v.size() - 1; i++)
	{
		for (int j = i + 1; j < (int)v.size(); j++)
		{
			int diff_y = v[i].second - v[j].second;
			if (diff_y * diff_y > dist)
			{
				break;
			}

			dist = min(dist, get_dist(v[i], v[j]));
		}
	}

	return dist;
}

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

	sort(a, a + n, [](auto &l, auto &r)
	{ 
		return l.first < r.first;
	});

	cout << go(0, n) << '\n';

	return 0;
}