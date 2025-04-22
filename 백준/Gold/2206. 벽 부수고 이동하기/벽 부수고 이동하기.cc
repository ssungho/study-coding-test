#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

constexpr int DIR_SIZE{4};
int dy[DIR_SIZE]{-1, 1, 0, 0};
int dx[DIR_SIZE]{0, 0, -1, 1};
int N{}, M{};
vector<vector<char>> map;
vector<vector<vector<bool>>> visited;

struct Node
{
    int y{}, x{}, count{};
    bool crash{};
};

int BFS(int y, int x)
{
    queue<Node> q;
    q.push({y, x, 1, false});
    visited[y][x][0] = true;

    int short_path = -1;

    while (!q.empty())
    {
        auto [current_y, current_x, current_count, current_crash] = q.front();
        q.pop();

        if (current_y == N && current_x == M)
        {
            short_path = current_count;
            break;
        }

        for (int i = 0; i < DIR_SIZE; i++)
        {
            int ny = current_y + dy[i];
            int nx = current_x + dx[i];
            if (0 < ny && ny <= N && 0 < nx && nx <= M)
            {
                if (map[ny][nx] == '0' && !visited[ny][nx][current_crash])
                {
                    q.push({ny, nx, current_count + 1, current_crash});
                    visited[ny][nx][current_crash] = true;
                }
                else if (map[ny][nx] == '1' && !visited[ny][nx][1] && !current_crash)
                {
                    q.push({ny, nx, current_count + 1, true});
                    visited[ny][nx][1] = true;
                }
            }
        }
    }

    return short_path;
}

int main(void)
{
    cin >> N >> M;

    map.resize(N + 1, vector<char>(M + 1, ' '));
    visited.resize(N + 1, vector<vector<bool>>(M + 1, vector<bool>(2, false)));

    for (int i = 1; i <= N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
        {
            map[i][j + 1] = temp[j];
        }
    }

    cout << BFS(1, 1);

    return 0;
}