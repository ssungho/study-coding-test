#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>

using namespace std;

constexpr int arr_size {50};
constexpr int dir_size {4};
constexpr int dy[dir_size]{-1, 0, 1, 0};
constexpr int dx[dir_size]{0, 1, 0, -1};

char map [arr_size][arr_size] {};
bool visited[arr_size][arr_size] {};
int n, m;

int bfs(int y, int x) {
    int max_count = 0;
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {y, x}});
    visited[y][x] = true;

    while (!q.empty()) {
        int current_count = q.front().first;
        int current_y = q.front().second.first;
        int current_x = q.front().second.second;
        q.pop();

        max_count = max(max_count, current_count);

        for (int dir = 0; dir < dir_size; dir++) {
            int ny = dy[dir] + current_y;
            int nx = dx[dir] + current_x;

            if (0 <= ny && ny < n && 0 <= nx && nx < m && 
                !visited[ny][nx] && map[ny][nx] == 'L') {
                q.push({current_count + 1, {ny, nx}});
                visited[ny][nx] = true;
            }
        }
    }
    
    memset(visited, 0, sizeof(visited));

    return max_count;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            map[i][j] = row[j];
        }
    }

    int answer = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'L') {
                answer = max(answer, bfs(i, j));
            }
        }
    }

    cout << answer << '\n';

    return 0;
}