#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, c, low, mid, high, result;
vector<ll> pos;

bool Check(ll target)
{
	ll cnt = 1;
	ll prev = pos.front();

	for (ll i = 1; i < n; i++)
	{
		ll curr = pos[i];
		
		if (curr - prev >= target)
		{
			cnt++;
			prev = curr;
		}
	}

	return cnt >= c;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> c;
	pos.resize(n);

	for (ll i = 0; i < n; i++)
	{
		cin >> pos[i];
		high = max(high, pos[i]);
	}

	sort(pos.begin(), pos.end());

	result = high;
	low = 1;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (true == Check(mid))
		{
			result = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	cout << result << '\n';

	return 0;
}