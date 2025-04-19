#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int BFS(vector<vector<int>>& graph, vector<vector<bool>>& visited, pair<int, int>& shark_pos, int shark_size) {
    int dy[]{-1, 0, 0, 1};
    int dx[]{0, -1, 1, 0};
    int graph_size = (int)graph.size();

    vector<vector<int>> move_graph(graph_size, vector<int>(graph_size, INT_MAX));
   
    queue<pair<pair<int, int>, int>> q;
    q.push({shark_pos, 0});
    visited[shark_pos.first][shark_pos.second] = true;

    while (!q.empty()) {
        shark_pos = q.front().first;
        int current_time = q.front().second;
        q.pop();

        bool eat = false;

        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + shark_pos.first;
            int nx = dx[i] + shark_pos.second;
            if (0 <= nx  && nx < graph_size && 0 <= ny && ny < graph_size && !visited[ny][nx]) {
                int fish_size = graph[ny][nx];

                if (fish_size <= shark_size) {
                    if (0 < fish_size && fish_size < shark_size) {
                        move_graph[ny][nx] = current_time + 1;
                    }
                    q.push({{ny, nx}, current_time + 1});
                    visited[ny][nx] = true;
                }
            }
        }
    }

    int time = INT_MAX;
    for (int i = 0; i < graph_size; i++) {
        for (int j = 0; j < graph_size; j++) {
            if (move_graph[i][j] < time) {
                time = move_graph[i][j];
                shark_pos = {i, j};
            }
        }
    }

    if (time != INT_MAX) {
        graph[shark_pos.first][shark_pos.second] = 0;
    }

    return time;
}

int main(void) {
    int N;
    cin >> N;

    vector<vector<int>> graph(N, vector<int>(N, 0));

    pair<int, int> shark_pos{};
    int shark_size = 2;
    int eat_count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 9) {
                shark_pos = {i, j};
                graph[i][j] = 0;
            }
        }
    }

    int total_time = 0;

    while (true) {
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        int time = BFS(graph, visited, shark_pos, shark_size);
        
        if (time == INT_MAX) {  
            break;
        }

        if (++eat_count == shark_size) {
            ++shark_size;
            eat_count = 0;
        }

        total_time += time;
    }
    
    cout << total_time;

    return 0;
}