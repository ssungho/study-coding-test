#include <iostream>
#include <vector>
using namespace std;

constexpr int MOD{1000000009};
constexpr int MAX_N{1000000};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;
        vector<long long> dp(MAX_N + 1, 0);

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        for (int i = 4; i <= n; i++)
        {
            dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % MOD;
        }

        cout << dp[n] << '\n';
    }

    return 0;
}