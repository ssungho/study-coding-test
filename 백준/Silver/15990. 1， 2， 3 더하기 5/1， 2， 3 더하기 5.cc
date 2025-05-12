#include <iostream>
#include <vector>

using namespace std;

constexpr long long LL_MOD{1000000009};
constexpr int MAX_N{100001};
long long dp[MAX_N][3] = {};

int main(void)
{
    int T;
    cin >> T;

    dp[1][0] = 1;
    dp[2][1] = 1;
    dp[3][0] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;

    while (T--)
    {
        int n;
        cin >> n;

        for (int i = 4; i <= n; i++)
        {
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % LL_MOD;
            dp[i][1] = (dp[i - 2][0] + dp[i - 2][2]) % LL_MOD;
            dp[i][2] = (dp[i - 3][0] + dp[i - 3][1]) % LL_MOD;
        }

        cout << (dp[n][0] + dp[n][1] + dp[n][2]) % LL_MOD << '\n';
    }

    return 0;
}