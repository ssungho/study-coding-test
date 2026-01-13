#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
ull n, k, result;

int main(void)
{
	cin >> n >> k;

	ull max_n = 1;
	while (max_n <= n)
	{
		max_n *= 2;
	}

	while (true)
	{
		int bit_cnt = 0;
		int add_num = 0;

		for (ull i = 1; i <= max_n; i *= 2)
		{
			if (n & i)
			{
				bit_cnt++;
				if (add_num == 0)
				{
					add_num = i;
				}
			}
		}

		if (bit_cnt <= k)
		{
			break;
		}

		n += add_num;
		result += add_num;
	}

	cout << result << '\n';

	return 0;
}