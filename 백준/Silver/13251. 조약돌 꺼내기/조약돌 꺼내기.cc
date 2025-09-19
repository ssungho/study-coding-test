#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> colors;
int n, m, k;

int main(void)
{
	cin >> m;
	colors.resize(m + 1);
	for (int i = 1; i <= m; i++)
	{
		cin >> colors[i];
		n += colors[i];
	}

	cin >> k;

	long double answer = 0.0;

	for (int i = 1; i <= m; i++)
	{
		if (colors[i] >= k)
		{
			long double temp = 1.0;
			
			for (int j = 0; j < k; j++)
			{
				temp *= (long double)(colors[i] - j) / (n - j);
			}

			answer += temp;
		}
	}

	cout << fixed << setprecision(9) << answer << '\n';

	return 0;
}