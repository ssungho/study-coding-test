#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    
    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    vector<vector<long long>> dp(N, vector<long long>(N, 0));
    dp[0][0] = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int move = board[i][j];

            if (dp[i][j] == 0 || move == 0)
            {
                continue;
            }

            int ny = i + move;
            int nx = j + move;

            if (ny < N)
            {
                dp[ny][j] += dp[i][j];
            }

            if (nx < N)
            {
                dp[i][nx] += dp[i][j];
            }
        }
    }

    cout << dp[N - 1][N - 1];

    return 0;
}