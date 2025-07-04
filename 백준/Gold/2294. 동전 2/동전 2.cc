#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;

    vector<int> coins(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    vector<int> dp(k + 1, INT_MAX);
    dp[0] = 0;
    
    for (int coin : coins)
    {
        for (int i = coin; i <= k; i++)
        {
            if (dp[i - coin] != INT_MAX) 
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    cout << (dp[k] == INT_MAX ? -1 : dp[k]) << '\n';

    return 0;
}