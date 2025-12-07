#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;

int main(void)
{
	cin >> n >> m;

	if (n == 1)
	{
		cnt = 1;
	}
	else if (n == 2)
	{
		if (m <= 6)
		{
			cnt = (m + 1) / 2;
		}
		else
		{
			cnt = 4;
		}
	}
	else if (n >= 3)
	{
		if (m <= 6)
		{
			cnt = min(m, 4);
		}
		else
		{
			cnt = m - 2;
		}
	}

	cout << cnt << '\n';

	return 0;
}