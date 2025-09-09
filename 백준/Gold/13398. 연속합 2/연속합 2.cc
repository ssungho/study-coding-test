#include <iostream>

using namespace std;

int a[100001]{};
int dp[100001][2]{};

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
	}

	int max_ele = a[1];

	dp[1][0] = a[1];

	for (int i = 2; i <= n; i++) 
	{
		dp[i][0] = max(a[i], a[i] + dp[i - 1][0]);
		dp[i][1] = max(dp[i - 1][1] + a[i], dp[i - 1][0]);
		max_ele = max(max_ele, max(dp[i][0], dp[i][1]));
	}
	
	cout << max_ele << '\n';

	return 0;
}