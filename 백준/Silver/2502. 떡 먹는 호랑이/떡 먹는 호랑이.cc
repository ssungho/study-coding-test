#include <bits/stdc++.h>
using namespace std;

int d, k, temp, first, second, dp1[31], dp2[31];

int main(void)
{
	cin >> d >> k;

	dp1[1] = 1;
	dp1[2] = 0;
	dp2[1] = 0;
	dp2[2] = 1;

	for (int i = 3; i <= d; i++)
	{
		dp1[i] = dp1[i - 1] + dp1[i - 2];
		dp2[i] = dp2[i - 1] + dp2[i - 2];
	}

	for (int i = 1; i <= k; i++)
	{
		temp = k - dp1[d] * i;
		if (temp % dp2[d] == 0)
		{
			second = temp / dp2[d];
			if (second >= 1)
			{
				first = i;
				break;
			}
		}
	}

	cout << first << '\n'
		 << second << '\n';

	return 0;
}