#include <bits/stdc++.h>
using namespace std;

int k, a_size;
int a[1025];
vector<int> depth[11];

void go(int s, int e, int d)
{
	if (s > e)
	{
		return;
	}
	
	int m = (s + e) / 2;
	go(s, m - 1, d + 1);
	depth[d].push_back(a[m]);
	go(m + 1, e, d + 1);
}

int main(void)
{
	cin >> k;

	a_size = (int)pow(2, k) - 1;
	for (int i = 1; i <= a_size; i++)
	{
		cin >> a[i];
	}

	go(1, a_size, 0);

	for (int i = 0; i < k; i++)
	{
		for (int node : depth[i])
		{
			cout << node << ' ';
		}
		cout << '\n';
	}

	return 0;
}