#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int dir_size{4};
int dy[dir_size]{-1, 1, 0, 0};
int dx[dir_size]{0, 0, -1, 1};

int N, M;
int start_y, start_x;
int dest_y, dest_x;

int BFS(vector<vector<char>>& map)
{
    int result = 0;
    queue<pair<int, int>> q;
    queue<pair<int, int>> hit_q;
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    q.push({start_y - 1, start_x - 1});
    visited[start_y - 1][start_x - 1] = true;

    while (true)
    {
        result++;

        while (!q.empty())
        {
            int current_y = q.front().first;
            int current_x = q.front().second;
            q.pop();

            for (int dir = 0; dir < dir_size; dir++)
            {
                int ny = dy[dir] + current_y;
                int nx = dx[dir] + current_x;

                if (0 <= ny && ny < N && 0 <= nx && nx < M && !visited[ny][nx])
                {
                    visited[ny][nx] = true;

                    if (map[ny][nx] == '1') hit_q.push({ny, nx});
                    else if (map[ny][nx] == '0') q.push({ny, nx});
                    else return result;
                }
            }
        }

        while (!hit_q.empty())
        {
            q.push(hit_q.front());
            map[hit_q.front().first][hit_q.front().second] = '0';
            hit_q.pop();
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> start_y >> start_x >> dest_y >> dest_x;
    vector<vector<char>> map(N, vector<char>(M, ' '));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    cout << BFS(map);

    return 0;
}