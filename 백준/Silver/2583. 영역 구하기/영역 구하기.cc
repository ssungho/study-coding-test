#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int BFS(vector<vector<bool>> &graph, vector<vector<bool>> &visited, int x, int y)
{
    int dy[]{1, -1, 0, 0};
    int dx[]{0, 0, -1, 1};

    queue<pair<int, int>> q;

    q.push({y, x});

    visited[y][x] = true;
    int area = 1;

    int graph_x = (int)graph[0].size();
    int graph_y = (int)graph.size();

    while (!q.empty())
    {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];

            if (ny >= 0 && ny < graph_y && nx >= 0 && nx < graph_x && !visited[ny][nx] && graph[ny][nx])
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
    int M, N, K;
    cin >> M >> N >> K;

    vector<vector<bool>> graph(N, vector<bool>(M, true));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for (int k = 0; k < K; k++)
    {
        pair<int, int> left_bottom, right_top;
        cin >> left_bottom.first >> left_bottom.second >> right_top.first >> right_top.second;

        for (int i = left_bottom.first; i < right_top.first; i++)
        {
            for (int j = left_bottom.second; j < right_top.second; j++)
            {
                graph[i][j] = false;
            }
        }
    }

    vector<int> areas;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!visited[i][j] && graph[i][j])
            {
                areas.push_back(BFS(graph, visited, j, i));
            }
        }
    }

    sort(areas.begin(), areas.end());

    cout << areas.size() << '\n';
    for (int area : areas)
    {
        cout << area << " ";
    }

    return 0;
}