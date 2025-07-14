#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

constexpr int dir_size{4};
constexpr int dy[dir_size]{-1, 0, 1, 0};
constexpr int dx[dir_size]{0, 1, 0, -1};
constexpr int max_n{50};

int map[max_n][max_n]{};
bool visited[max_n][max_n]{};
int n, l, r;

bool bfs(int y, int x) {
    queue<pair<int, int>> q;
    queue<pair<int, int>> visited_q;
    q.push({y, x});
    visited[y][x] = true;

    int people = 0;
    int cities = 0;

    while (!q.empty()) {
        int current_y = q.front().first;
        int current_x = q.front().second;
        q.pop();
        
        visited_q.push({current_y, current_x});
        people += map[current_y][current_x];
        cities += 1;
        
        for (int dir = 0; dir < dir_size; dir++) {
            int ny = dy[dir] + current_y;
            int nx = dx[dir] + current_x;
        
            if (ny < 0 || ny >= n || nx < 0 || nx >= n) 
                continue;
            if (visited[ny][nx])
                continue;
            
            int diff = abs(map[current_y][current_x] - map[ny][nx]);
            if (l <= diff && diff <= r) {
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
    }

    if (cities <= 1) return false;

    int update = people / cities;

    while (!visited_q.empty()) {
        int current_y = visited_q.front().first;
        int current_x = visited_q.front().second;
        visited_q.pop();
        map[current_y][current_x] = update;
    }

    return true;
}

int main(void) {
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    int day = 0;

    while (true) {
        bool move = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    bool result = bfs(i, j);
                    if (!move) move = result;
                }
            }
        }
        
        if (!move) break;
        day++;

        memset(visited, 0, sizeof(visited));
    }

    cout << day << '\n';

    return 0;
}