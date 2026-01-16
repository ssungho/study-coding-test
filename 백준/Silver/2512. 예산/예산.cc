#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
ull n, m, result, a[100000];

bool check(ull mid)
{
	ull sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] <= mid)
		{
			sum += a[i];
		}
		else
		{
			sum += mid;
		}
	}
	return sum <= m;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	ull max_ele = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		max_ele = max(max_ele, a[i]);
	}
	cin >> m;

	ull left, mid, right;
	left = 1;
	right = max_ele;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (check(mid))
		{
			result = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << result << '\n';

	return 0;
}