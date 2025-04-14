#include <iostream>

using namespace std;

int main(void) {

    int mod = 10007;

    int n;
    cin >> n;

    int dp[1001][10]{{}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, };
    

    for (int i = 2; i <= n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j < 10; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= mod;
        }
    }

    int answer = 0;
    for (int i = 0; i < 10; i++) {
        answer += dp[n][i];
        answer %= mod;
    }

    cout << answer;

    return 0;
}