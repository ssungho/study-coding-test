#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<bool> dp(N + 1);
    dp[1] = true;
    dp[2] = false;
    dp[3] = true;
    dp[4] = true;

    for (int i = 5; i <= N; i++)
    {
        if (!dp[i - 1] || !dp[i - 3] || !dp[i - 4])
            dp[i] = true;
        else
            dp[i] = false;
    }

    if (dp[N])
        cout << "SK";
    else
        cout << "CY";

    return 0;
}