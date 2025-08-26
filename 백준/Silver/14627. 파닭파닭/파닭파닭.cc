#include <iostream>
#include <vector>
#include <climits>

using namespace std;
using ll = long long;

int s, c;
vector<ll> v;

bool Check(ll target)
{
	ll cnt = 0;

	for (int i = 0; i < s; i++)
	{
		cnt += v[i] / target;
	}

	return cnt >= c;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> s >> c;
	v.resize(s);

	ll left = 1;
	ll right = INT_MAX;
	ll result = INT_MAX - 1;
	ll sum = 0;
 
	for (int i = 0; i < s; i++)
	{
		cin >> v[i];
		sum += v[i];
	}

	while (left <= right)
	{
		ll mid = (left + right) / 2;

		if (Check(mid))
		{
			result = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	result = sum - result * c;

	cout << result << '\n';

	return 0;
}