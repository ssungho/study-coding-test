#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
ull n, target, result, a[1001];
unordered_set<ull> s;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			s.emplace(a[i] + a[j]);
		}
	}

	sort(a + 1, a + n + 1, less<>());

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			target = a[i] - a[j];
			if (s.end() != s.find(target))
			{
				result = max(result, a[i]);
			}
		}
	}

	cout << result << '\n';

	return 0;
}