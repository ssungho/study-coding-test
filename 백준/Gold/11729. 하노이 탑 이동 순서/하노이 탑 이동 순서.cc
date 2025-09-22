#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> v;

void hanoi(int num, int from, int mid, int to)
{
	if (num == 0) 
	{
		return;
	}

	hanoi(num - 1, from, to, mid);
	v.push_back({from, to});
	hanoi(num - 1, mid, from, to);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	hanoi(n, 1, 2, 3);

	cout << v.size() << '\n';

	for (auto p : v)
	{
		cout << p.first << " " << p.second << '\n';
	}

	return 0;
}