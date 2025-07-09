#include <iostream>
#include <memory.h>

using namespace std;

constexpr int dir_size{4};
constexpr int dy[dir_size]{-1, 0, 1, 0};
constexpr int dx[dir_size]{0, 1, 0, -1};
constexpr int max_size{50};
bool map[max_size][max_size]{};
bool visited[max_size][max_size]{};
int T, N, M, K;

void dfs(int y, int x)
{
    visited[y][x] = true;

    for (int dir = 0; dir < dir_size; dir++)
    {
        int ny = dy[dir] + y;
        int nx = dx[dir] + x;
        if (0 <= ny && ny < N && 0 <= nx && nx < M &&
            map[ny][nx] && !visited[ny][nx])
        {
            dfs(ny, nx);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;

    while (T--)
    {
        cin >> N >> M >> K;

        memset(visited, 0, sizeof(visited));
        memset(map, 0, sizeof(map));

        for (int i = 0; i < K; i++)
        {
            int y, x;
            cin >> y >> x;
            map[y][x] = true;
        }

        int count = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (!visited[i][j] && map[i][j])
                {
                    dfs(i, j);
                    count++;
                }
            }
        }

        cout << count << '\n';
    }
    return 0;
}