#include <iostream>
#include <vector>

using namespace std;

constexpr int DIR_SIZE{4};
int dy[DIR_SIZE]{-1, 1, 0, 0};
int dx[DIR_SIZE]{0, 0, -1, 1};
int N, M;

int DFS(vector<vector<int>>& map, vector<vector<int>>& dp, int y, int x)
{
    if (y == N - 1 && x == M - 1)
        return 1;
    if (dp[y][x] != -1)
        return dp[y][x];

    dp[y][x] = 0;

    for (int dir = 0; dir < DIR_SIZE; dir++)
    {
        int ny = dy[dir] + y;
        int nx = dx[dir] + x;
        if (0 <= ny && ny < N && 0 <= nx && nx < M && map[ny][nx] < map[y][x])
        {
            dp[y][x] += DFS(map, dp, ny, nx);
        }
    }

    return dp[y][x];
}

int main(void)
{
    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    vector<vector<int>> dp(N, vector<int>(M, -1));
    cout << DFS(map, dp, 0, 0);

    return 0;
}