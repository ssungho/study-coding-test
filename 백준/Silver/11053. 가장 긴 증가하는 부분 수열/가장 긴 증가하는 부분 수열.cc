#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<int> v(n + 1, 0);
	vector<int> dp(n + 1, 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (v[i] > v[j])
			{
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << '\n';

	return 0;
}