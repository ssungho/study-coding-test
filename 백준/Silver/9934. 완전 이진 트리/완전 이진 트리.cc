#include <bits/stdc++.h>

using namespace std;

int k, a_size, a[1025];
vector<int> v[11];

void go(int s, int e, int depth)
{
	if (s > e)
	{
		return;
	}

	int mid = (s + e) / 2;
	v[depth].push_back(a[mid]);
	go(s, mid - 1, depth + 1);
	go(mid + 1, e, depth + 1);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> k;

	a_size = (int)pow(2, k);
	for (int i = 1; i < a_size; i++)
	{
		cin >> a[i];
	}

	go(1, a_size - 1, 0);

	for (int i = 0; i < k; i++)
	{
		for (auto i : v[i])
		{
			cout << i << " ";
		}
		cout << '\n';
	}

	return 0;
}