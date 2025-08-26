#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
vector<ll> v;

int main(void)
{
	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int left = 0;
	int right = n - 1;

	ll prev = INT_MAX;
	vector<ll> temp(2, 0);

	while (left < right)
	{
		ll mid = (left + right) / 2;
		ll val = v[left] + v[right];

		if (abs(val) <= prev)
		{
			temp[0] = v[left];
			temp[1] = v[right];
			prev = abs(val);
		}

		if (val > 0)
		{
			right--;
		}
		else
		{
			left++;
		}
	}

	cout << temp[0] << " " << temp[1] << '\n';

	return 0;
}