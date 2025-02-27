#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int N, M;

int map[8][8]{};
int test_map[8][8]{};
bool visited[8][8]{};

int dy[4]{1, -1, 0, 0};
int dx[4]{0, 0, -1, 1};

vector<pair<int, int>> safe_area;
vector<pair<int, int>> virus_area;

void BFS(int y, int x)
{
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;

    while (!q.empty())
    {
        pair<int, int> front = q.front();
        int current_y = front.first;
        int current_x = front.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_y = current_y + dy[i];
            int next_x = current_x + dx[i];

            if (next_y >= 0 && next_y < N && next_x >= 0 && next_x < M &&
                test_map[next_y][next_x] == 0 && !visited[next_y][next_x])
            {
                q.push({next_y, next_x});
                visited[next_y][next_x] = true;
                test_map[next_y][next_x] = 2;
            }
        }
    }
}

int CheckSafeArea()
{
    int count = 0;

    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            if (test_map[y][x] == 0)
                count++;

    return count;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cin >> map[y][x];

            if (map[y][x] == 0)
                safe_area.push_back({y, x});
            else if (map[y][x] == 2)
                virus_area.push_back({y, x});
        }
    }

    int max_area = -1;

    int safe_area_size = safe_area.size();

    for (int i = 0; i < safe_area_size; i++)
    {
        for (int j = 0; j < safe_area_size; j++)
        {
            for (int k = 0; k < safe_area_size; k++)
            {
                if (i == j || i == k || j == k)
                    continue;

                memset(visited, 0, sizeof(bool) * 64);
                memset(test_map, 0, sizeof(int) * 64);

                memcpy(test_map, map, sizeof(int) * 64);

                pair<int, int> wall_pos = safe_area[i];
                test_map[wall_pos.first][wall_pos.second] = 1;

                wall_pos = safe_area[j];
                test_map[wall_pos.first][wall_pos.second] = 1;

                wall_pos = safe_area[k];
                test_map[wall_pos.first][wall_pos.second] = 1;

                int virus_count = virus_area.size();

                for (int h = 0; h < virus_count; h++)
                {
                    BFS(virus_area[h].first, virus_area[h].second);
                }

                max_area = max(CheckSafeArea(), max_area);
            }
        }
    }

    cout << max_area;

    return 0;
}