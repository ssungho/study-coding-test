#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int DIR_SIZE = 4;
int dy[DIR_SIZE]{-1, 1, 0, 0};
int dx[DIR_SIZE]{0, 0, -1, 1};
int R, C;
int max_count = 0;

void DFS(vector<vector<char>> &map, vector<bool> &visited, int y, int x, int count)
{
    max_count = max(max_count, count);

    for (int i = 0; i < DIR_SIZE; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (0 < ny && ny <= R && 0 < nx && nx <= C)
        {
            int next = map[ny][nx] - 'A';

            if (!visited[next])
            {
                visited[next] = true;
                DFS(map, visited, ny, nx, count + 1);
                visited[next] = false;
            }
        }
    }
}

int main(void)
{
    cin >> R >> C;

    vector<vector<char>> map(R + 1, vector<char>(C + 1));

    for (int i = 1; i <= R; i++)
    {
        string row;
        cin >> row;

        for (size_t j = 0; j < row.size(); j++)
        {
            map[i][j + 1] = row[j];
        }
    }

    vector<bool> visited(26, false);

    visited[map[1][1] - 'A'] = true;
    DFS(map, visited, 1, 1, 1);

    cout << max_count;

    return 0;
}