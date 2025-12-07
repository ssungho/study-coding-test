#include <bits/stdc++.h>
using namespace std;

int n, k, result;
string s;

int main(void)
{
	cin >> n >> k >> s;

	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'P')
		{
			for (int j = -k; j <= k; j++)
			{
				if (s[i + j] == 'H')
				{
					result++;
					s[i + j] = 'X';
					break;
				}
			}
		}
	}

	cout << result << '\n';

	return 0;
}