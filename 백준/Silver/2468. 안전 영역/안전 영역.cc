#include <iostream>
#include <memory.h>

using namespace std;

int map[101][101]{};
bool visited[101][101]{};
int dy[4]{1, -1, 0, 0};
int dx[4]{0, 0, -1, 1};
int N;

void DFS(int y, int x, int height)
{
    visited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (nx >= 1 && nx <= N && ny >= 1 && ny <= N &&
            !visited[ny][nx] && map[y][x] > height)
        {
            DFS(ny, nx, height);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> map[i][j];
        }
    }

    int max_count = 0;
    for (int i = 0; i <= 100; i++)
    {
        int count = 0;
        for (int j = 1; j <= 100; j++)
        {
            for (int k = 1; k <= 100; k++)
            {
                if (!visited[j][k] && map[j][k] > i)
                {
                    DFS(j, k, i);
                    count++;
                }
            }
        }

        max_count = max(max_count, count);
        memset(visited, 0, sizeof(visited));
    }

    cout << max_count;

    return 0;
}