#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[2001];
int dp[2001];

int main(void)
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		dp[i] = 1;
	}

	for (int i = n; i >= 1; i--)
	{
		for (int j = n; j > i; j--)
		{
			if (a[i] > a[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	cout << n - *max_element(dp + 1, dp + n + 1) << '\n';

	return 0;
}