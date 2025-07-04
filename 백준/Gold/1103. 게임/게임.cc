#include <iostream>
#include <string>

using namespace std;

constexpr int DIR_SIZE{4};
constexpr int dy[DIR_SIZE]{-1, 1, 0, 0};
constexpr int dx[DIR_SIZE]{0, 0, -1, 1};

int N, M;
char board[51][51]{};
bool visited[51][51]{};
int dp[51][51]{};

int dfs(int y, int x)
{
    if (y < 0 || y >= N || x < 0 || x >= M || board[y][x] == 'H')
    {
        return 0;
    }

    if (visited[y][x])
    {
        return -1;
    }

    if (dp[y][x] != -1)
    {
        return dp[y][x];
    }

    visited[y][x] = true;

    int move = board[y][x] - '0';
    int max_depth = 0;

    for (int dir = 0; dir < DIR_SIZE; dir++)
    {
        int ny = move * dy[dir] + y;
        int nx = move * dx[dir] + x;
        int next = dfs(ny, nx);

        if (next == -1)
            return -1;

        max_depth = max(max_depth, next);
    }

    visited[y][x] = false;

    dp[y][x] = max_depth + 1;
    
    return dp[y][x];
}

int main(void)
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++)
        {
            board[i][j] = row[j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << dfs(0, 0) << '\n';

    return 0;
}