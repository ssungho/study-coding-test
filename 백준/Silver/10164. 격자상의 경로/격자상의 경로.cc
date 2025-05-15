#include <iostream>
#include <vector>

using namespace std;
constexpr int MAX_N{16};
constexpr int MAX_M{16};

int main(void)
{
    int N, M, K;
    cin >> N >> M >> K;

    int answer = 0;
    int dp[MAX_N][MAX_M]{};

    for (int i = 1; i <= N; i++)
    {
        dp[i][1] = 1;
    }
    
    for (int i = 1; i <= M; i++)
    {
        dp[1][i] = 1;
    }

    int start_i = 2;
    int start_j = 2;

    for (int i = start_i; i <= N; i++)
    {
        for (int j = start_j; j <= M; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

            if (M * (i - 1) + j == K)
            {
                for (int k = i; k <= N; k++)
                {
                    dp[k][j] = dp[i][j];
                }

                for (int k = j; k <= M; k++)
                {
                    dp[i][k] = dp[i][j];
                }

                start_i = i;
                start_j = j;
                i++;
            }
        }
    }

    cout << dp[N][M];

    return 0;
}