#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m, arr[100001], low, mid, high, result;

bool Check(ll mid)
{
    int cnt = 0;
    int money = 0;

    for (int i = 1; i <= n; i++)
    {
        if (money < arr[i])
        {
            money = mid;
            cnt++;
        }
        
        money -= arr[i];
    }

    return cnt <= m;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        low = max(low, arr[i]);
    }

    high = 100000 * 10000;
    result = high;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (true == Check(mid))
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