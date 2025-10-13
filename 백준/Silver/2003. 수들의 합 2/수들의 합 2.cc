#include <bits/stdc++.h>
using namespace std;

int n, m, l, r, result, a[10001], s[10001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s[i] = a[i] + s[i - 1];
	}

	r = 1;
	while (r <= n)
	{
		int sum = s[r] - s[l];
		if (sum <= m)
		{
			r++;
			if (sum == m)
			{
				result++;
			}
		}
		else if (sum > m)
		{
			l++;
		}
	}

	cout << result << '\n';

	return 0;
}