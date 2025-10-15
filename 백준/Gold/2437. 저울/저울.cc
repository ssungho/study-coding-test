#include <bits/stdc++.h>
using namespace std;

int n, answer, a[1000];

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		cin >> a[i];
	}
	sort(a, a + n);

	for (int i = 0; i < n; i++)
	{
		if (a[i] <= answer + 1)
			answer += a[i];
		else break;
	}

	answer++;
	cout << answer << '\n';

	return 0;
}