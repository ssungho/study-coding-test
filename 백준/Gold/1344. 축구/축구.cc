#include <iostream>

using namespace std;

const int n = 18;
double dp[20][20][20]{};
double pa, pb;

bool IsPrime(int x)
{
	if (x < 2)
	{
		return false;
	}

	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main(void)
{
	cin >> pa >> pb;

	pa *= 0.01;
	pb *= 0.01;

	dp[0][0][0] = 1.0;

	for (int i = 1; i <= n; i++)
	{
		for (int a = 0; a <= i; a++)
		{
			for (int b = 0; b <= i; b++)
			{
				if (a > 0)
					dp[i][a][b] += dp[i - 1][a - 1][b] * pa * (1.0 - pb);

				if (b > 0)
					dp[i][a][b] += dp[i - 1][a][b - 1] * (1.0 - pa) * pb;

				if (a > 0 && b > 0)
					dp[i][a][b] += dp[i - 1][a - 1][b - 1] * pa * pb;

				dp[i][a][b] += dp[i - 1][a][b] * (1.0 - pa) * (1.0 - pb);
			}
		}
	}

	double result = 0.0;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (IsPrime(i) || IsPrime(j))
			{
				result += dp[18][i][j];
			}
		}
	}

	cout << result << '\n';

	return 0;
}