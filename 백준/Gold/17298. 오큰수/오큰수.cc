#include <bits/stdc++.h>

using namespace std;

int n, x;
stack<pair<int, int>> s;
vector<int> v;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	v.resize(n, -1);

	for (int i = 0; i < n; i++)
	{
		cin >> x;
		while (s.empty() == false && s.top().second < x)
		{
			v[s.top().first] = x;
			s.pop();
		}
		s.push({i, x});
	}

	for (auto i : v)
	{
		cout << i << ' ';
	}

	return 0;
}