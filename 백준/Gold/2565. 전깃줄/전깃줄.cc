#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++)
	{
		pair<int, int> p;
		cin >> p.first >> p.second;
		v.push_back(p);
	}

	sort(v.begin(), v.end());

	vector<int> dp(n, 1);

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i].second > v[j].second)
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	cout << n - *max_element(dp.begin(), dp.end()) << '\n';

	return 0;
}