#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int DIR_SIZE{4};
int dy[DIR_SIZE]{1, -1, 0, 0};
int dx[DIR_SIZE]{0, 0, -1, 1};
int N, L, R;

bool BFS(vector<vector<int>> &graph, vector<vector<bool>> &visited, int start_y, int start_x)
{
    queue<pair<int, int>> unions;
    queue<pair<int, int>> q;

    unions.push({start_y, start_x});
    q.push({start_y, start_x});
    visited[start_y][start_x] = true;

    int total = graph[start_y][start_x];

    while (!q.empty())
    {
        auto [current_y, current_x] = q.front();
        q.pop();

        for (int i = 0; i < DIR_SIZE; i++)
        {
            int ny = dy[i] + current_y;
            int nx = dx[i] + current_x;

            if (ny >= 0 && ny < N && nx >= 0 && nx < N && !visited[ny][nx])
            {
                int diff = abs(graph[current_y][current_x] - graph[ny][nx]);
                if (L <= diff && diff <= R)
                {
                    q.push({ny, nx});
                    unions.push({ny, nx});
                    total += graph[ny][nx];
                    visited[ny][nx] = true;
                }
            }
        }
    }

    if (unions.size() == 1)
    {
        return false;
    }

    int average = total / (int)unions.size();

    while (!unions.empty())
    {
        auto [pos_y, pos_x] = unions.front();
        unions.pop();
        graph[pos_y][pos_x] = average;
    }

    return true;
}

int main(void)
{
    cin >> N >> L >> R;

    vector<vector<int>> graph(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
        }
    }

    int cnt = 0;
    while (true)
    {
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        bool change = false;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visited[i][j])
                {
                    if (BFS(graph, visited, i, j))
                    {
                        change = true;
                    }
                }
            }
        }

        if (!change)
        {
            break;
        }

        cnt++;
    }

    cout << cnt;

    return 0;
}