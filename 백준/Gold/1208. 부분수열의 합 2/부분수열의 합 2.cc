#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll n, s, result;

void go(vector<ll>& v, vector<ll>& ret, int start, int end, ll sum)
{
	if (start == end)
	{
		ret.push_back(sum);
		return;
	}

	go(v, ret, start + 1, end, sum);
	go(v, ret, start + 1, end, sum + v[start]);
}

int main(void)
{
	cin >> n >> s;
	vector<ll> a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	vector<ll> left_sum, right_sum;	

	go(a, left_sum, 0, n / 2, 0);
	go(a, right_sum, n / 2, n, 0);

	sort(right_sum.begin(), right_sum.end());

	for (ll current : left_sum)
	{
		ll target = s - current;

		auto lb = lower_bound(right_sum.begin(), right_sum.end(), target);
		auto ub = upper_bound(right_sum.begin(), right_sum.end(), target);

		result += (ub - lb);
	}

	// 공집합.
	if (s == 0)
	{ 
		result--;
	}

	cout << result << '\n';

	return 0;
}