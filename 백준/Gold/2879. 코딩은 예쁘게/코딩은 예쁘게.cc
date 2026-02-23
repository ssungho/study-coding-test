#include <bits/stdc++.h>
using namespace std;

int n, result, src[1001], dst[1001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> src[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		cin >> dst[i];
	}

	int prev = 0;
	for (int i = 1; i <= n; i++) 
	{
		int diff = dst[i] - src[i];

		bool check1 = (diff > 0 && prev < 0);
		bool check2 = (diff < 0 && prev > 0);

		if (check1 || check2)
		{
        	prev = 0;
		}

		if (abs(diff) > abs(prev))
		{
			result += abs(diff) - abs(prev);
		}

		prev = diff;
	}

	cout << result << '\n';

	return 0;
}