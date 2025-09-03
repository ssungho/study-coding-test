#include <iostream>
#include <memory.h>

using namespace std;

int n, m;
int arr[2001]{};
int dp[2001][2001]{};

bool Check(int start, int end)
{
	if (dp[start][end] != -1)
	{
		return dp[start][end];
	}

	if (start >= end)
	{
		return dp[start][end] = 1;
	}

	if (arr[start] != arr[end])
	{
		return dp[start][end] = 0;
	}

	if (dp[start + 1][end - 1] == 1)
	{
		return dp[start][end] = 1;
	}
	
	return dp[start][end] = Check(start + 1, end - 1);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	memset(dp, -1, sizeof(dp));

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		cout << Check(s, e) << '\n';
	}

	return 0;
}