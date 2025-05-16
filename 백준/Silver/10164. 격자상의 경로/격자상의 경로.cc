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
    int dp1[MAX_N][MAX_M]{};

    for (int i = 1; i <= N; i++)
    {
        dp1[i][1] = 1;
    }

    for (int i = 1; i <= M; i++)
    {
        dp1[1][i] = 1;
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = 2; j <= M; j++)
        {
            dp1[i][j] = dp1[i - 1][j] + dp1[i][j - 1];
        }
    }

    if (K != 0)
    {
        int dp2[MAX_N][MAX_M]{};

        int start_i = (K - 1) / M + 1;
        int start_j = (K - 1) % M + 1;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                dp2[i][j] = 1;
            }
        }

        for (int i = start_i + 1; i <= N; i++)
        {
            for (int j = start_j + 1; j <= M; j++)
            {
                dp2[i][j] = dp2[i - 1][j] + dp2[i][j - 1];
            }
        }
        
        cout << dp1[start_i][start_j] * dp2[N][M];
    }
    else
    {
        cout << dp1[N][M];
    }

    return 0;
}