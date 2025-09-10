#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, k;

ll Count(int mid)
{
    ll result = 0;
    for (ll i = 1; i <= n; i++)
    {
        result += min(mid / i, n);
    }
    return result;
}

int main(void)
{
    cin >> n >> k;

    ll left = 1;
    ll right = k;
    ll result = 0;

    while (left <= right)
    {
        ll mid = (left + right) / 2;

        if (Count(mid) < k)
        {
            left = mid + 1;
        }
        else
        {
            result = mid;
            right = mid - 1;
        }
    }

    cout << result << '\n';

    return 0;
}