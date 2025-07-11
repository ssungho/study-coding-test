//! 12 : 39 시작

#include <iostream>
#include <memory.h>

using namespace std;

const int max_index{100};
const int arr_size{max_index + 1};
const int dir_size{4};
const int dy[dir_size]{-1, 0, 1, 0};
const int dx[dir_size]{0, 1, 0, -1};
int n, m;

int graph[arr_size][arr_size] {};
bool visited[arr_size][arr_size][2] {};

int CountCheese(int y, int x) {
    int count = 1;
    visited[y][x][0] = true;
    for (int dir = 0; dir < dir_size; dir++) {
        int ny = dy[dir] + y;
        int nx = dx[dir] + x;
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
            continue;
        }
        if (!visited[ny][nx][0] && graph[ny][nx] == 1) {
            count += CountCheese(ny, nx);
        }
    }
    return count;
}

void DFS(int y, int x) {
    visited[y][x][1] = true;
    for (int dir = 0; dir < dir_size; dir++) {
        int ny = dy[dir] + y;
        int nx = dx[dir] + x;
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
            continue;
        }
        if (!visited[ny][nx][1]) {
            if (graph[ny][nx] == 0) {
                DFS(ny, nx);
            }
            if (graph[ny][nx] == 1) {
                visited[ny][nx][1] = true;
            }
        }
    }
}

void Melt() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j][1]) {
                graph[i][j] = 0;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    int prev_cheese_count = 0;
    int time = 0;

    while (true) {
        memset (visited, 0, sizeof(visited));
        int cheese_count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j] == 1 && !visited[i][j][0]) {
                    cheese_count += CountCheese(i, j);
                }
            }
        }
        
        if (cheese_count == 0) {
            break;
        }

        prev_cheese_count = cheese_count;
        DFS(0, 0);
        Melt();
        time++;
    }

    cout << time << '\n' << prev_cheese_count << '\n';

    return 0;
}