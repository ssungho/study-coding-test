#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;

    vector<int> dp(k + 1, INT_MAX);
    dp[0] = 0;
    vector<int> coins;

    for (int i = 0; i < n; i++)
    {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    for (int coin : coins)
    {
        for (int j = coin; j <= k; j++)
        {
            if (dp[j - coin] != INT_MAX) 
            {
                dp[j] = min(dp[j], dp[j - coin] + 1);
            }
        }
    }

    int answer = dp[k] == INT_MAX ? -1 : dp[k];
    cout << answer;

    return 0;
}