#include <bits/stdc++.h>

using namespace std;

int n, m, t, ret, a[500000];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	sort(a, a + m);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		ret = upper_bound(a, a + m, t) - lower_bound(a, a + m, t);
		cout << ret << '\n';
	}

	return 0;
}