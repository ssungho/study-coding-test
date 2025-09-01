#include <bits/stdc++.h>

using namespace std;

int n, k;
int dp[100001]{};
int items[101][2]{};

int main(void)
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> items[i][0] >> items[i][1];
	}

	for (int i = 1; i <=n; i++) 
	{
		int w = items[i][0];
		int v = items[i][1];

		for (int j = k; j >= w; j--)
		{
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	
	cout << dp[k] << '\n';

	return 0;
}