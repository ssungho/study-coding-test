#include <bits/stdc++.h>
using namespace std;

int n, m, result, a[10001], s[10001];

int main(void)
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s[i] = a[i] + s[i - 1];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			int perfix_sum = s[i] - s[j];
			if (perfix_sum == m)
				result++;
		}
	}

	cout << result << '\n';

	return 0;
}