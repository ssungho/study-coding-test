#include <bits/stdc++.h>
using namespace std;

int n, l, d, temp;
deque<pair<int, int>> dq;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> l;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;

		while (dq.size() && dq.back().second > temp)
		{
			dq.pop_back();
		}

		dq.push_back({i, temp});

		while (dq.front().first <= i - l)
		{
			dq.pop_front();
		}

		cout << dq.front().second << " ";
	}

	return 0;
}