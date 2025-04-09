#include <iostream>
#include <vector>

using namespace std;

int dy[]{1, 1, 0, -1, -1, -1, 0, 1};
int dx[]{0, 1, 1, 1, 0, -1, -1, -1};

void DFS(vector<vector<int>> &graph, vector<vector<bool>> &visited, int y, int x)
{
    visited[y][x] = true;
    for (int i = 0; i < 8; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && ny < (int)graph.size() &&
            nx >= 0 && nx < (int)graph[0].size() &&
            !visited[ny][nx] && graph[ny][nx] == 1)
        {
            DFS(graph, visited, ny, nx);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int w, h;
    while (true)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;

        vector<vector<int>> graph(h, vector<int>(w, 0));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> graph[i][j];
            }
        }

        vector<vector<bool>> visited(h, vector<bool>(w, false));
        int count = 0;
        
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (graph[i][j] == 1 && !visited[i][j])
                {
                    DFS(graph, visited, i, j);
                    count++;
                }
            }
        }

        cout << count << '\n';
    }

    return 0;
}