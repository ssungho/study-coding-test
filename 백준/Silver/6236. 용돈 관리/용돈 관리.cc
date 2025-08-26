#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int n, m;

bool Check(vector<ll> &v, int mid)
{
	int cnt = 0;
	ll sum = 0;

	for (int i = 0; i < n; i++)
	{
		if (sum < v[i]) 
		{
			cnt++;
			sum = mid;
		}

		sum -= v[i];
	}

	return cnt <= m;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	vector<ll> v(n, 0);
	ll left = 0, mid, right = 100000 * 10000;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		left = max(left, v[i]);
	}

	ll result = right;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (Check(v, mid))
		{
			right = mid - 1;
			result = min(mid, result);
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << result << '\n';

	return 0;
}