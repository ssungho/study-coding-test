#include <cstdio>

constexpr int max{10001};
int dp[max]{1, };

int main(void)
{
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j < max; j++)
        {
            dp[j] += dp[j - i];
        }
    }

    while (T--)
    {
        int n;
        scanf("%d", &n);
        printf("%d \n", dp[n]);
    }

    return 0;
}