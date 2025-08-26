#include <iostream>
#include <vector>
#include <climits>

using namespace std;
using ll = long long;

ll n, m;
vector<ll> v;

bool Check(ll target)
{
	ll cnt = m;

	for (int i = 0; i < m; i++)
	{
		cnt += target / v[i];
	}

	return cnt >= n;
}

int main(void)
{
	cin >> n >> m;

	v.resize(m);

	for (int i = 0; i < m; i++)
	{
		cin >> v[i];
	}

	if (n <= m)
	{
		cout << n << '\n';
		return 0;
	}

	ll left = 0;
	ll right = 60000000000;
	ll time = 0;

	while (left <= right)
	{
		ll mid = (left + right) / 2;

		if (Check(mid))
		{
			time = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	int temp = m;
	for (int i = 0; i < m; i++)
	{
		temp += (time - 1) / v[i];
	}

	for (int i = 0; i < m; i++)
	{
		if (time % v[i] == 0)
		{
			temp++;
		}

		if (temp == n)
		{
			cout << i + 1 << '\n';
			break;
		}
	}

	return 0;
}