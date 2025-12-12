#include <bits/stdc++.h>

using namespace std;

int n, a[40001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	vector<int> lis;
	for (int i = 1; i <= n; i++)
	{
		if (lis.empty())
		{
			lis.push_back(a[i]);
			continue;
		}

		auto iter = lower_bound(lis.begin(), lis.end(), a[i]);
		if (iter == lis.end())
		{
			lis.push_back(a[i]);
		}
		else
		{
			*iter = a[i];
		}
	}

	cout << lis.size() << '\n';

	return 0;
}