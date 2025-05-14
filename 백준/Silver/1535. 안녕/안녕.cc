#include <iostream>

using namespace std;

constexpr int MAX_N{20};
constexpr int MAX_HP{100};

int main(void)
{
    int L[MAX_N]{};
    int J[MAX_N]{};
    int dp[MAX_HP + 1]{};

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> L[i];
    for (int i = 0; i < N; i++)
        cin >> J[i];

    for (int i = 0; i < N; i++)
    {
        for (int j = MAX_HP; j - L[i] > 0; j--)
            dp[j] = max(dp[j], dp[j - L[i]] + J[i]);
    }

    cout << dp[100];

    return 0;
}