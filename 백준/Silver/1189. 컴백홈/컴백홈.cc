#include <iostream>
#include <vector>

using namespace std;

constexpr int DIR_SIZE{4};
int dy[DIR_SIZE]{1, -1, 0, 0};
int dx[DIR_SIZE]{0, 0, -1, 1};
int R, C, K;

void Backtracking(vector<vector<char>>& map,
                  vector<vector<bool>>& visited,
                  int count, int y, int x, int &answer)
{
    if (count >= K)
    {
        if (y == 0 && x == C - 1 && count == K)
        {
            answer++;
        }

        return;
    }

    for (int dir = 0; dir < DIR_SIZE; dir++)
    {
        int ny = dy[dir] + y;
        int nx = dx[dir] + x;
        if (0 <= ny && ny < R && 0 <= nx && nx < C &&
            map[ny][nx] == '.' && !visited[ny][nx])
        {
            visited[ny][nx] = true;
            Backtracking(map, visited, count + 1, ny, nx, answer);
            visited[ny][nx] = false;
        }
    }
}

int main(void)
{
    cin >> R >> C >> K;
    vector<vector<char>> map(R, vector<char>(C, '.'));
    vector<vector<bool>> visited(R, vector<bool>(C, false));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
        }
    }

    int answer = 0;
    visited[R - 1][0] = true;
    Backtracking(map, visited, 1, R - 1, 0, answer);
    cout << answer << '\n';

    return 0;
}