#include <bits/stdc++.h>

using namespace std;

int n, m, t, a[100001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> t;
		cout << binary_search(a + 1, a + n + 1, t) << '\n';
	}
	
	return 0;
}