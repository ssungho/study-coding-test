#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

constexpr int DIR_SIZE{4};
int dy[DIR_SIZE]{-1, 1, 0, 0};
int dx[DIR_SIZE]{0, 0, -1, 1};

bool visited[101][101]{};
bool light[101][101]{};

int BFS(vector<vector<vector<pair<int, int>>>> &room, int N)
{
    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = true;
    light[1][1] = true;
    int cnt = 1;

    while (!q.empty())
    {
        int current_y = q.front().first;
        int current_x = q.front().second;
        q.pop();

        vector<pair<int, int>> &connect = room[current_y][current_x];

        bool light_on = false;
        for (auto &pos : connect)
        {
            if (!light[pos.first][pos.second])
            {
                light[pos.first][pos.second] = true;
                light_on = true;
                cnt++;
            }
        }

        if (light_on)
        {
            for (int i = 1; i <= N; i++)
            {
                memset(visited[i], false, N + 1);
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

    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<vector<pair<int, int>>>> room(N + 1, vector<vector<pair<int, int>>>(N + 1));
    for (int i = 0; i < M; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        room[y][x].push_back({b, a});
    }

    cout << BFS(room, N);

    return 0;
}