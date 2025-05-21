#include <iostream>
#include <vector>

using namespace std;

constexpr int DIR_SIZE{4};
constexpr int dy[DIR_SIZE]{-1, 0, 1, 0};
constexpr int dx[DIR_SIZE]{0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int pos_y, pos_x, dir;
    cin >> pos_y >> pos_x >> dir;

    vector<vector<int>> map(N, vector<int>(M, 0));
    vector<vector<int>> visited(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    int count = 0;

    while (true)
    {
        if (!map[pos_y][pos_x] && 
            !visited[pos_y][pos_x]) 
        {
            visited[pos_y][pos_x] = true;
            count++;
        }

        bool find = false;

        for (int i = 0; i < DIR_SIZE; i++)
        {
            int ny = dy[i] + pos_y;
            int nx = dx[i] + pos_x;

            if (map[ny][nx] == 0 && visited[ny][nx] == 0)
            {
                find = true;
            }
        }

        if (find) 
        {
            dir = (dir + 3) % DIR_SIZE;

            int ny = dy[dir] + pos_y;
            int nx = dx[dir] + pos_x;

            if (visited[ny][nx] == 0 && map[ny][nx] == 0)
            {
                pos_y = ny;
                pos_x = nx;
            }
        }
        else
        {
            int ny = pos_y - dy[dir];
            int nx = pos_x - dx[dir];

            if (map[ny][nx] == 1)
            {
                break;
            }

            pos_y = ny;
            pos_x = nx;
        }
    }

    cout << count;

    return 0;
}