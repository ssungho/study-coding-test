#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

constexpr int dir_size{4};
constexpr int dy[dir_size]{-1, 1, 0, 0};
constexpr int dx[dir_size]{0, 0, -1, 1};

struct Node
{
    int y{};
    int x{};
    int count{};
    bool is_fire{};
};

int main(void)
{
    int R, C;
    cin >> R >> C;

    pair<int, int> start_pos{};
    queue<pair<int, int>> fire_pos;
    vector<vector<bool>> fire_visited(R, vector<bool>(C, false));

    vector<vector<char>> graph(R, vector<char>(C));
    for (int i = 0; i < R; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < C; j++)
        {
            graph[i][j] = row[j];

            if (graph[i][j] == 'J')
            {
                start_pos = {i, j};
            }
            else if (graph[i][j] == 'F')
            {
                fire_pos.push({i, j});
                fire_visited[i][j] = true;
            }
        }
    }

    queue<Node> q;
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    q.push({start_pos.first, start_pos.second, 0, false});
    visited[start_pos.first][start_pos.second] = true;

    while (!fire_pos.empty())
    {
        q.push({fire_pos.front().first, fire_pos.front().second, 0, true});
        fire_pos.pop();
    }

    while (!q.empty())
    {
        int pos_y = q.front().y;
        int pos_x = q.front().x;
        int count = q.front().count;
        bool is_fire = q.front().is_fire;
        q.pop();

        if (!is_fire && graph[pos_y][pos_x] == 'F')
            continue;

        for (int dir = 0; dir < dir_size; dir++)
        {
            int ny = pos_y + dy[dir];
            int nx = pos_x + dx[dir];

            if ((ny < 0 || ny == R || nx < 0 || nx == C) && !is_fire)
            {
                cout << count + 1;
                return 0;
            }
            else if (0 <= ny && ny < R && 0 <= nx && nx < C)
            {
                if (!is_fire && !visited[ny][nx] && graph[ny][nx] == '.')
                {
                    visited[ny][nx] = true;
                    q.push({ny, nx, count + 1, is_fire});
                }
                else if (is_fire && !fire_visited[ny][nx] && graph[ny][nx] != '#')
                {
                    fire_visited[ny][nx] = true;
                    q.push({ny, nx, 0, is_fire});
                    graph[ny][nx] = 'F';
                }
            }
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}