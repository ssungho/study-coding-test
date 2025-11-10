#include <bits/stdc++.h>
using namespace std;

int n, m, j, a[21], result, pos_l, pos_r;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	cin >> j;
	for (int i = 0; i < j; i++)
	{
		cin >> a[i];
	}

	pos_l = 1;
	pos_r = pos_l + m - 1;
	for (int i = 0; i < j; i++)
	{
		if (pos_l <= a[i] && a[i] <= pos_r)
		{
			continue;
		}
		else if (a[i] < pos_l)
		{
			result += (pos_l - a[i]);
			pos_l = a[i];
			pos_r = pos_l + m - 1;
		}
		else
		{
			result += (a[i] - pos_r);
			pos_r = a[i];
			pos_l = pos_r - m + 1;
		}
	}

	cout << result << '\n';

	return 0;
}