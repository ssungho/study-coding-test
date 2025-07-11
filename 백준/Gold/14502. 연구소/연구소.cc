#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

constexpr int dir_size{4};
constexpr int arr_size{8};
constexpr int dy[dir_size]{-1, 0, 1, 0};
constexpr int dx[dir_size]{0, 1, 0, -1};

int N, M;
int lab[arr_size][arr_size] {};
int temp[arr_size][arr_size] {};
bool visited[arr_size][arr_size] {};
vector<pair<int, int>> safe_zones;
vector<pair<int, int>> virus_zones;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 0) {
                safe_zones.push_back({i, j});
            }
            else if (lab[i][j] == 2) {
                virus_zones.push_back({i, j});
            }
        }
    }

    int max_safe_count = 0;
    int safe_zone_count = (int)safe_zones.size();
    int virus_zone_count = (int)virus_zones.size();
    for (int i = 0; i < safe_zone_count - 2; i++) {
        for (int j = i + 1; j < safe_zone_count - 1; j++) {
            for (int k = j + 1; k < safe_zone_count; k++) {
                memset(visited, 0, sizeof(visited));
                memcpy(temp, lab, sizeof(lab));
                temp[safe_zones[i].first][safe_zones[i].second] = 1;
                temp[safe_zones[j].first][safe_zones[j].second] = 1;
                temp[safe_zones[k].first][safe_zones[k].second] = 1;

                int infected = 0;
                queue<pair<int, int>> q;
                for (auto& p : virus_zones) {
                    q.push(p);
                    visited[p.first][p.second] = true;
                }
                while (!q.empty()) {
                    int current_y = q.front().first;
                    int current_x = q.front().second;
                    q.pop();
                    
                    for (int dir = 0; dir < dir_size; dir++) {
                        int ny = dy[dir] + current_y;
                        int nx = dx[dir] + current_x;
                        if (0 <= ny && ny < N && 0 <= nx && nx < M && !visited[ny][nx] && temp[ny][nx] == 0) {
                            q.push({ny, nx});
                            visited[ny][nx] = true;
                            infected++;
                        }
                    }
                }

                int current_safe_count = safe_zone_count - infected - 3;
                max_safe_count = max(max_safe_count, current_safe_count);
            }
        }
    }

    cout << max_safe_count << '\n';

    return 0;
}