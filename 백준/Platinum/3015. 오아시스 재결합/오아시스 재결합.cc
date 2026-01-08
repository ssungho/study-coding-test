#include <bits/stdc++.h>
using namespace std;

int n, x;
long long result;
stack<pair<int, int>> s;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;

		int cnt = 1;

		while (!s.empty() && s.top().first < x)
		{
			result += s.top().second;
			s.pop();
		}

		if (!s.empty() && s.top().first == x)
		{
			result += s.top().second;
			cnt = s.top().second + 1;
			s.pop();
		}

		if (!s.empty())
		{
			result++;
		}

		s.push({x, cnt});
	}

	cout << result << '\n';

	return 0;
}