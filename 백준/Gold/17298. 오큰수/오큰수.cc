#include <bits/stdc++.h>
using namespace std;

int n, a[1000001], answer[1000001];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	stack<int> s;
	memset(answer, -1, sizeof(answer));

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		while (s.size() && a[s.top()] < a[i])
		{
			answer[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 1; i <= n; i++)
	{
		cout << answer[i] << ' ';
	}
	cout << '\n';

	return 0;
}