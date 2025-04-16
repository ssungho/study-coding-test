#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<int> dp(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        dp[i] = i;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i - j * j] + 1, dp[i]);
        }
    }

    cout << dp[N];

    return 0;
}