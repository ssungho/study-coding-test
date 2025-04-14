#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n;

        vector<int> v(n, 0);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        cin >> m;

        vector<int> dp(m + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++)
        {
            int coin = v[i];
            for (int j = coin; j <= m; j++)
            {
                dp[j] += dp[j - coin];
            }
        }

        cout << dp[m] << '\n';
    }

    return 0;
}