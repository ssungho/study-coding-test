#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll m, n;

bool Check(vector<ll> &v, ll mid)
{
	ll num = 0;

	for (int i = 0; i < m; i++)
	{
		num += v[i] / mid;

		if (v[i] % mid)
		{
			num++;
		}
	}

	return n >= num;
}

int main(void)
{
	cin >> n >> m;
	vector<ll> v(m, 0);

	ll high = 0;
	ll low = 1;

	for (int i = 0; i < m; i++)
	{
		cin >> v[i];
		high = max(high, v[i]);
	}

	ll result = high;

	while (low <= high)
	{
		ll mid = (low + high) / 2;

		if (true == Check(v, mid))
		{
			result = min(result, mid);
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	cout << result << '\n';

	return 0;
}