#include <bits/stdc++.h>
using namespace std;

int n, x, part_cnt, visitor, max_visitor, a[250001], s[250001];

int main(void)
{
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s[i] = a[i] + s[i - 1];
	}

	max_visitor = s[x];
	if (max_visitor != 0)
	{
		part_cnt = 1;
	}

	for (int i = x + 1; i <= n; i++)
	{
		visitor = s[i] - s[i - x];
		if (visitor > max_visitor)
		{
			max_visitor = visitor;
			part_cnt = 1;
		}
		else if (visitor == max_visitor && visitor != 0)
		{
			part_cnt++;
		}
	}

	if (max_visitor != 0)
	{
		cout << max_visitor << '\n'
			 << part_cnt << '\n';
	}
	else
	{
		cout << "SAD" << '\n';
	}

	return 0;
}