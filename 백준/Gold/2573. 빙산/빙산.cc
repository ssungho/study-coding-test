#include <iostream>
#include <memory.h>

using namespace std;

constexpr int MAX_SIZE{300};
constexpr int DIR_SIZE{4};

int N, M;
int graph[MAX_SIZE][MAX_SIZE]{};
int record[MAX_SIZE][MAX_SIZE]{};
bool visited[MAX_SIZE][MAX_SIZE]{};
int dy[DIR_SIZE]{-1, 1, 0, 0};
int dx[DIR_SIZE]{0, 0, -1, 1};

void DFS(int y, int x)
{
    if (visited[y][x])
        return;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && ny < N && nx >= 0 && nx < M && graph[ny][nx] == 0)
        {
            record[y][x]++;
        }
    }

    visited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && ny < N && nx >= 0 && nx < M &&
            !visited[ny][nx] && graph[ny][nx] > 0)
        {
            DFS(ny, nx);
        }
    }
}

int main(void)
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> graph[i][j];
        }
    }

    int year = 0;

    while (true)
    {
        int count = 0;

        for (int i = 1; i < N - 1; i++)
        {
            for (int j = 1; j < M - 1; j++)
            {
                if (graph[i][j] > 0 && !visited[i][j])
                {
                    DFS(i, j);
                    count++;
                }
            }
        }

        if (count >= 2)
        {
            break;
        }

        if (count == 0)
        {
            year = 0;
            break;
        }

        year++;

        for (int i = 1; i < N - 1; i++)
        {
            for (int j = 1; j < M - 1; j++)
            {
                graph[i][j] = max(0, graph[i][j] - record[i][j]);
            }
        }

        for (int i = 0; i < N; i++)
        {
            memset(visited[i], false, M);
            memset(record[i], 0, M * sizeof(int));
        }
    }

    cout << year;

    return 0;
}