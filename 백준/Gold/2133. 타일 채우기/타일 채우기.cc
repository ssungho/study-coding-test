#include <iostream>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int dp[31]{};
    dp[0] = 1;
    dp[2] = 3;
    for (int i = 4; i <= N; i += 2)
    {
        dp[i] = 4 * dp[i - 2] - dp[i - 4];
    }

    cout << dp[N];

    return 0;
}