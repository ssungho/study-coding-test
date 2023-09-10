#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int town[1002][1002];
int visited[1002][1002];

void BFS(int size, int y, int x)
{
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};

    visited[y][x] = true;
    queue<pair<int, int>> q;
    q.push({y, x});
    while (!q.empty())
    {
        int curr_y = q.front().first;
        int curr_x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = curr_y + dy[i];
            int nx = curr_x + dx[i];
            if (ny > 0 && nx > 0 && ny < size + 1 && nx < size + 1 && !visited[ny][nx] && town[ny][nx] == 1)
            {
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
    }
}

int main(void)
{
    int N;
    cin >> N;
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            int temp;
            cin >> temp;
            town[i][j] = temp;
        }
    }
    int count = 0;
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            if (!visited[i][j] && town[i][j] == 1)
            {
                BFS(N, i, j);
                count++;
            }
        }
    }
    cout << count;
    return 0;
}