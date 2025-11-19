#include <bits/stdc++.h>
using namespace std;

int n, m, city, parent[201], a[201][201];

int Find(int x)
{
	if (parent[x] == x)
		return x;

	return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
	int parent_a = Find(a);
	int parent_b = Find(b);

	if (parent_a != parent_b)
	{
		if (parent_a < parent_b)
		{
			parent[parent_b] = parent_a;
		}
		else
		{
			parent[parent_a] = parent_b;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
            if (a[i][j])
            {
    			Union(i, j);
            }
		}
	}

	int top = -1;
	for (int i = 0; i < m; i++)
	{
		cin >> city;
		if (top == -1)
		{
			top = Find(city);
		}
		else
		{
			if (top != Find(city))
			{
				cout << "NO\n";
				return 0;
			}
		}
	}

	cout << "YES\n";

	return 0;
}