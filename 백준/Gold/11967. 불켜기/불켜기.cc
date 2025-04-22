#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int DIR_SIZE{4};
int dy[DIR_SIZE]{-1, 1, 0, 0};
int dx[DIR_SIZE]{0, 0, -1, 1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool visited[101][101]{};
    bool light[101][101]{};
    int N, M;
    cin >> N >> M;

    vector<vector<vector<pair<int, int>>>> room(N + 1, vector<vector<pair<int, int>>>(N + 1));
    for (int i = 0; i < M; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        room[y][x].push_back({b, a});
    }

    queue<pair<int, int>> q;

    q.push({1, 1});
    visited[1][1] = true;
    light[1][1] = true;

    int count = 1;

    while (!q.empty())
    {
        int current_y = q.front().first;
        int current_x = q.front().second;
        q.pop();

        vector<pair<int, int>> &connect = room[current_y][current_x];

        for (auto &pos : connect)
        {
            if (!light[pos.first][pos.second])
            {
                light[pos.first][pos.second] = true;
                count++;

                for (int i = 0; i < DIR_SIZE; i++)
                {
                    int ny = dy[i] + pos.first;
                    int nx = dx[i] + pos.second;
                    if (0 < ny && ny <= N && 0 < nx && nx <= N &&
                        visited[ny][nx] && light[ny][nx])
                    {
                        visited[pos.first][pos.second] = true;
                        q.push({pos.first, pos.second});
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < DIR_SIZE; i++)
        {
            int ny = dy[i] + current_y;
            int nx = dx[i] + current_x;
            if (0 < ny && ny <= N && 0 < nx && nx <= N &&
                !visited[ny][nx] && light[ny][nx])
            {
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }

    cout << count;

    return 0;
}