#include <iostream>
#include <queue>
#include <climits>

using namespace std;

constexpr int dir_size{4};
constexpr int dy[dir_size]{-1, 0, 1, 0};
constexpr int dx[dir_size]{0, 1, 0, -1};

constexpr int h_dir_size{8};
constexpr int hdy[h_dir_size]{-2, -1, 1, 2, 2, 1, -1, -2};
constexpr int hdx[h_dir_size]{1, 2, 2, 1, -1, -2, -2, -1};

constexpr int max_h{200};
constexpr int max_w{200};
constexpr int max_k{31};

int k, w, h;
vector<vector<int>> graph;
bool visited[max_h][max_w][max_k]{};

int main(void)  {
	cin >> k >> w >> h;
	graph.resize(h, vector<int>(w, 0));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> graph[i][j];
		}
	}

	int total_move = INT_MAX;
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({{0, 0}, {0, 0}});
	visited[0][0][0] = 0;

	while (!q.empty()) {
		int move = q.front().first.first;
		int h_move = q.front().first.second;
		int current_y = q.front().second.first;
		int current_x = q.front().second.second;
		q.pop();

		if (current_y == h - 1 && current_x == w - 1) {
			total_move = min(total_move, move);
		}

		for (int dir = 0; dir < dir_size; dir++) {
			int ny = current_y + dy[dir];
			int nx = current_x + dx[dir];

			if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
				continue;
			}

			if (!visited[ny][nx][h_move] && graph[ny][nx] == 0) {
				q.push({{move + 1, h_move}, {ny, nx}});
				visited[ny][nx][h_move] = true;
			}
		}

		if (h_move >= k) {
			continue;
		}

		for (int dir = 0; dir < h_dir_size; dir++) {
			int ny = current_y + hdy[dir];
			int nx = current_x + hdx[dir];

			if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
				continue;
			}

			if (!visited[ny][nx][h_move + 1] && graph[ny][nx] == 0) {
				q.push({{move + 1, h_move + 1}, {ny, nx}});
				visited[ny][nx][h_move + 1] = true;
			}
		}
	}

	if (total_move == INT_MAX) total_move = -1;

	cout << total_move << '\n';

	return 0;
}