#include <bits/stdc++.h>

using namespace std;

int n, m, low, high;

bool Check(vector<int> &v, int mid)
{
	int sum = 0;
	int cnt = 1;

	for (int i = 0; i < n; i++)
	{
		sum += v[i];
		if (sum > mid)
		{
			cnt++;
			sum = v[i];
		}
	}

	return cnt <= m;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	vector<int> a(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		low = max(low, a[i]);
		high += a[i];
	}

	int left = low;
	int right = high;
	int answer = high;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (Check(a, mid))
		{
			right = mid - 1;
			answer = min(answer, mid);
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << answer << '\n';

	return 0;
}