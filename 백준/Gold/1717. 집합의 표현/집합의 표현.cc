#include <bits/stdc++.h>
using namespace std;

int n, m, oper, a, b, parents[1000001];

int Find(int x)
{
	if (x == parents[x])
	{
		return x;
	}

	return parents[x] = Find(parents[x]);
}

void Union(int l, int r)
{
	int parent_l = Find(l);
	int parent_r = Find(r);

	if (parent_l == parent_r)
	{
		return;
	}

	if (l < r)
	{
		parents[parent_r] = parent_l;
	}
	else
	{
		parents[parent_l] = parent_r;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	for (int i = 1; i <= 1000000; i++)
	{
		parents[i] = i;
	}

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> oper >> a >> b;

		if (oper == 0)
		{
			Union(a, b);
		}
		else if (oper == 1)
		{
			if (Find(a) == Find(b))
			{
				cout << "yes\n";
			}
			else
			{
				cout << "no\n";
			}
		}
	}
	
	return 0;
}