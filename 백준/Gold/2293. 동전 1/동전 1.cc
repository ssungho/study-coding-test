#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> dp(k + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        int val = v[i];
        for (int j = val; j <= k; j++)
        {
            dp[j] += dp[j - val];
        }
    }

    cout << dp[k];

    return 0;
}