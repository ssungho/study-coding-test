#include <iostream>
#include <vector>
#define MAX 100000

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector<int> coins = {2, 5};
    vector<int> dp(n + 1, MAX);
    dp[2] = 1;
    dp[5] = 1;

    for (int coin : coins)
    {
        for (int i = coin; i <= n; i++)
        {
            dp[i] = min(dp[i - coin] + 1, dp[i]);
        }
    }

    if (dp[n] >= MAX)
        cout << -1;
    else
        cout << dp[n];

    return 0;
}