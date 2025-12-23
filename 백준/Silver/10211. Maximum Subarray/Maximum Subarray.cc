#include <bits/stdc++.h>
using namespace std;

int t, n, l, r, result, a[1001], s[1001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--)
	{
		s[0] = 0;
		result = INT_MIN;

		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			s[i] = a[i] + s[i - 1];
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				int sub_sum = s[i] - s[j - 1];
				if (sub_sum > result)
				{
					result = sub_sum;
				}
			}
		}

		cout << result << '\n';
	}

	return 0;
}