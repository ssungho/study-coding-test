#include <iostream>
#include <queue>
using namespace std;

int graph[501][501];
bool visited[501][501];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int BFS(int y, int x)
{
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;
    int area = 1;

    while (!q.empty())
    {
        int curr_y = q.front().first;
        int curr_x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = curr_y + dy[i];
            int nx = curr_x + dx[i];
            if (ny > 0 && nx > 0 && ny < 501 && nx < 501 && !visited[ny][nx] && graph[ny][nx] == 1)
            {
                q.push({ny, nx});
                visited[ny][nx] = true;
                area++;
            }
        }
    }
    return area;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            int temp;
            cin >> temp;
            graph[i][j] = temp;
        }
    }

    int count = 0;
    int max_area = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (graph[i][j] == 1 && !visited[i][j])
            {
                int area = BFS(i, j);
                if (area > max_area)
                    max_area = area;
                count++;
            }
        }
    }
    cout << count << '\n' << max_area;

    return 0;
}