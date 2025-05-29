#include <iostream>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int dp[31]{};
    dp[2] = 3;
    dp[4] = 11;
    for (int i = 6; i <= N; i += 2)
    {
        dp[i] = 4 * dp[i - 2] - dp[i - 4];
    }

    cout << dp[N];

    return 0;
}