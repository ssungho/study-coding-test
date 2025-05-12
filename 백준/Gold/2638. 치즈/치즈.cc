#include <iostream>
#include <vector>

using namespace std;

constexpr int DIR_SIZE{4};
int dy[DIR_SIZE]{-1, 1, 0, 0};
int dx[DIR_SIZE]{0, 0, -1, 1};
int N, M;

void DfS(vector<vector<int>> &graph, vector<vector<bool>> &visited, int y, int x, bool &melt)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if (0 <= ny && ny < N && 0 <= nx && nx < M)
        {
            if (!visited[ny][nx])
            {
                visited[ny][nx] = true;
                if (graph[ny][nx] == 0)
                {
                    DfS(graph, visited, ny, nx, melt);
                }
            }
            else if (visited[ny][nx] && graph[ny][nx] == 1)
            {
                graph[ny][nx] = 0;
                melt = true;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> graph[i][j];
        }
    }

    int time = 0;
    while (true)
    {
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        bool melt = false;
        DfS(graph, visited, 0, 0, melt);

        if (!melt)
            break;

        time++;
    }

    cout << time;

    return 0;
}