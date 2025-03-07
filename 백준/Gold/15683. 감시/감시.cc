#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int N, M;
int map[8][8];
vector<pair<int, int>> cctv_pos;
vector<int> rotation;
int min_area = 64;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<int>> cctv_dir = {
    {},
    {0},
    {0, 2},
    {0, 1},
    {0, 1, 2},
    {0, 1, 2, 3}
};

void Count()
{
    int copy[8][8];
    memcpy(copy, map, sizeof(map));

    int pos_count = cctv_pos.size();
    for (int i = 0; i < pos_count; i++)
    {
        int y = cctv_pos[i].first;
        int x = cctv_pos[i].second;
        int cctv_type = map[y][x];

        for (int d : cctv_dir[cctv_type])
        {
            int dir = (d + rotation[i]) % 4;
            int cur_y = y, cur_x = x;

            while (true)
            {
                cur_y += dy[dir];
                cur_x += dx[dir];

                if (cur_y < 0 || cur_y >= N || 
                    cur_x < 0 || cur_x >= M ||
                     copy[cur_y][cur_x] == 6)
                    break;

                if (copy[cur_y][cur_x] == 0)
                    copy[cur_y][cur_x] = -1;
            }
        }
    }

    int area = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (copy[i][j] == 0)
                area++;
        }
    }

    min_area = min(min_area, area);
}

void Backtracking(int n)
{
    if (n == (int)cctv_pos.size())
    {
        Count();
        return;
    }

    for (int j = 0; j < 4; j++)
    {
        rotation.push_back(j);
        Backtracking(n + 1);
        rotation.pop_back();
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] >= 1 && map[i][j] <= 5)
            {
                cctv_pos.push_back({i, j});
            }
        }
    }

    Backtracking(0);
    cout << min_area << endl;

    return 0;
}