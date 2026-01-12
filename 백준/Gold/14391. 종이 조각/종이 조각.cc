#include <bits/stdc++.h>
using namespace std;

int n, m, ret, mask_max, a[4][4];
string row;

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> row;
		for (int j = 0; j < m; j++)
		{
			a[i][j] = row[j] - '0';
		}
	}

	mask_max = 1 << (n * m);
	for (int mask = 0; mask < mask_max; mask++)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int cur = 0;
			for (int j = 0; j < m; j++)
			{
				int index = i * m + j;
				if ((mask & (1 << index)) == 0)
				{
					cur = cur * 10 + a[i][j];
				}
				else
				{
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}

		for (int j = 0; j < m; j++)
		{
			int cur = 0;
			for (int i = 0; i < n; i++)
			{
				int index = i * m + j;
				if ((mask & (1 << index)) != 0)
				{
					cur = cur * 10 + a[i][j];
				}
				else
				{
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}

		ret = max(ret, sum);
	}

	cout << ret << '\n';

	return 0;
}