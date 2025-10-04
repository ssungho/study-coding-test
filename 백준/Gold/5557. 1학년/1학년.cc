#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, a[101];
ll dp[101][21];

bool check(ll num)
{
    return (0 <= num && num <= 20);
}

ll go(int index, ll num)
{
    if (index == n - 1)
    {
        if (num == a[n])
        {
            return 1;
        }
        return 0;
    }

    ll& ret = dp[index][num];
    if (ret != -1)
    {
        return ret;
    }

    ret = 0;
    if (check(num + a[index + 1]))
    {
        ret += go(index + 1, num + a[index + 1]);
    }
    if (check(num - a[index + 1]))
    {
        ret += go(index + 1, num - a[index + 1]);
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << go(1, a[1]) << '\n';
    
    return 0;
}