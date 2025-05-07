#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int DIR_SIZE{4};
int dy[DIR_SIZE]{-1, 1, 0, 0};
int dx[DIR_SIZE]{0, 0, -1, 1};

int H, W;

void BFS(vector<vector<int>> &graph, vector<vector<bool>> &visited)
{
    queue<pair<int, int>> q;

    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty())
    {
        int current_y = q.front().first;
        int current_x = q.front().second;
        q.pop();

        for (int dir = 0; dir < DIR_SIZE; dir++)
        {
            int ny = current_y + dy[dir];
            int nx = current_x + dx[dir];

            if (0 <= ny && ny < H && 0 <= nx && nx < W)
            {
                if (graph[current_y][current_x] == 0 && graph[ny][nx] == 1)
                {
                    visited[ny][nx] = true;
                }
                else if (graph[ny][nx] == 0 && !visited[ny][nx])
                {
                    q.push({ny, nx});
                    visited[ny][nx] = true;
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> H >> W;
    vector<vector<int>> graph(H, vector<int>(W, 0));

    int count = 0;
    int prev_result = 0;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> graph[i][j];

            if (graph[i][j] == 1) 
            {
                prev_result++;
            }
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));

    while (true)
    {
        int sum = 0;

        BFS(graph, visited);

        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (graph[i][j] == 1)
                {
                    if (visited[i][j])
                    {
                        graph[i][j] = 0;
                    }
                    else
                    {
                        sum++;
                    }
                }

                visited[i][j] = false;
            }
        }

        count++;

        if (sum == 0)
        {
            break;
        }

        prev_result = sum;
    }

    cout << count << '\n'
         << prev_result;

    return 0;
}