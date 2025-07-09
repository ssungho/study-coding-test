#include <iostream>
#include <string>
#include <queue>

using namespace std;

constexpr int dir_size{4};
constexpr int max_index{100};
constexpr int max_size{max_index + 1};
constexpr int dy[dir_size]{-1, 0, 1, 0};
constexpr int dx[dir_size]{0, 1, 0, -1};
char maze[max_size][max_size]{};
bool visited[max_size][max_size]{};

int main(void)
{
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        string row;
        cin >> row;

        for (int j = 1; j <= M; j++)
        {
            maze[i][j] = row[j - 1];
        }
    }

    queue<pair<int, pair<int, int>>> q;
    q.push({1, {1, 1}});
    visited[1][1] = true;

    while (!q.empty())
    {
        int current_count = q.front().first;
        int current_y = q.front().second.first;
        int current_x = q.front().second.second;
        q.pop();

        if (current_y == N && current_x == M)
        {
            cout << current_count << '\n';
            break;
        }

        for (int dir = 0; dir < dir_size; dir++)
        {
            int ny = dy[dir] + current_y;
            int nx = dx[dir] + current_x;

            if (0 < ny && ny <= N && 0 < nx && nx <= M &&
                maze[ny][nx] == '1' && !visited[ny][nx])
            {
                visited[ny][nx] = true;
                q.push({current_count + 1, {ny, nx}});
            }
        }
    }

    return 0;
}