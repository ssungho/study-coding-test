// 16:18

#include <iostream>
#include <queue>

using namespace std;

constexpr int max_count{10000};
constexpr int dir_size{4};
constexpr int dy[dir_size]{-1, 0, 1, 0};
constexpr int dx[dir_size]{0, 1, 0, -1};

int n;
vector<vector<int>> graph;
vector<vector<int>> visited;
vector<vector<pair<int, int>>> group;

void BFS(int y, int x, int check) {
	vector<pair<int, int>> temp;
	queue<pair<int, int>> q;
	q.push({y, x});
	visited[y][x] = check;

	while (!q.empty()) {
		int current_y = q.front().first;
		int current_x = q.front().second;
		q.pop();

		temp.push_back({current_y, current_x});

		for (int i = 0; i < dir_size; i++) {
			int ny = current_y + dy[i];
			int nx = current_x + dx[i];
			if (0 > ny || ny >= n || 
				0 > nx || nx >= n) {
				continue;
			}
			
			if (graph[ny][nx] == 1 && visited[ny][nx] == -1) {
				q.push({ny, nx});
				visited[ny][nx] = check;
			}
		}
	}

	group.push_back(temp);
}

int DistanceOtherLand(int index) {
	vector<pair<int, int>>& v = group[index];
	vector<vector<int>> copied_visited(visited);

	queue<pair<int, pair<int, int>>> q;
	for (auto& p : v) {
		q.push({0, p});
	}

	while (!q.empty()) {
		int current_count = q.front().first;
		int current_y = q.front().second.first;
		int current_x = q.front().second.second;
		q.pop();

		for (int i = 0; i < dir_size; i++) {
			int ny = current_y + dy[i];
			int nx = current_x + dx[i];
			if (0 > ny || ny >= n || 
				0 > nx || nx >= n) {
				continue;
			}
			
			if (copied_visited[ny][nx] != index) {
				if (copied_visited[ny][nx] == -1) {
					q.push({current_count + 1, { ny, nx }});
					copied_visited[ny][nx] = index;
				}
				else {
					return current_count;
				}
			}
		}
	}

	return 0;
}

int main(void) {
	cin >> n;

	graph.resize(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	visited.resize(n, vector<int>(n, -1));

	int start = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == 1 && visited[i][j] == -1) {
				BFS(i, j, start);
				start++;
			}
		}
	}

	int result = max_count;

	for (int i = 0; i < start; i++) {
		result = min(result, DistanceOtherLand(i));
	}

	cout << result << '\n';

	return 0;
}