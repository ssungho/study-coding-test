#include <bits/stdc++.h>
using namespace std;

int n, result, a[200000];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n);

	int index = n / 2;
	if (n % 2 == 0) 
	{
		index--;
	}

	result = a[index];
	cout << result << '\n';

	return 0;
}