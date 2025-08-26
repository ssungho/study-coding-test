// 15:19

#include <iostream>
#include <vector>
#include <climits>

using namespace std;
using ll = long long;

ll x, y, z;

int main(void)
{
	cin >> x >> y;
	z = y * 100 / x;

	ll left = 0;
	ll right = INT_MAX;
	ll result = -1;

	if (x != y)
	{
		while (left <= right)
		{
			ll mid = (left + right) / 2;
			if (z != (ll)((y + mid) * 100 / (x + mid)))
			{
				result = mid;
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
	}

	cout << result << '\n';

	return 0;
}