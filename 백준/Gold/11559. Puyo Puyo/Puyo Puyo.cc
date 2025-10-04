#include <bits/stdc++.h>

using namespace std;

const int dy[4]{-1, 0, 1, 0}, dx[4]{0, 1, 0, -1};
const int max_row = 12, max_col = 6;
string kind = ".RGBPY";
char field[max_row][max_col], after_field[max_row][max_col];
bool visited[max_row][max_col];
int ret;

struct Node {
	int y, x, cnt;
};

void order_field() {
	for (int col = 0; col < max_col; col++) {
		int cursor = max_row - 1;
		bool reserved = false;
		for (int row = max_row - 1; row >= 0; row--) {
			if (field[row][col] == '.' && reserved == false) {
				cursor = row;
				reserved = true;
			}
			else if (field[row][col] != '.' && reserved == true) {
				field[cursor][col] = field[row][col];
				field[row][col] = '.';
				cursor--;
			}
		}
	}
}

bool bfs_field(int y, int x, char color) {
	queue<pair<int, int>> pos;
	queue<Node> q;
	q.push({y, x, 1});
	pos.push({y, x});
	visited[y][x] = true;

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + cur.y;
			int nx = dx[i] + cur.x;
			if (ny < 0 || ny >= max_row || nx < 0 || nx >= max_col) {
				continue;
			}
			if (field[ny][nx] == color && visited[ny][nx] == false) {
				q.push({ny, nx, cur.cnt + 1});
				visited[ny][nx] = true;
				pos.push({ny, nx});
			}
		}
	}

	if (pos.size() >= 4) {
		while (!pos.empty()) {
			after_field[pos.front().first][pos.front().second] = '.';
			pos.pop();
		}
		return true;
	}

	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < max_row; i++) {
		for (int j = 0; j < max_col; j++) {
			cin >> field[i][j];
		}
	}

	memcpy(after_field, field, sizeof(field));
	
	while (true) {
		bool counted = false;
		memcpy(after_field, field, sizeof(field));
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < max_row; i++) {
			for (int j = 0; j < max_col; j++) {
				if (field[i][j] != '.' && visited[i][j] == false) {
					bool popped = bfs_field(i, j, field[i][j]); 
					if (popped) {
						counted = true;
					}
				}
			}
		}
		if (counted) {
			memcpy(field, after_field, sizeof(field));
			order_field();
			ret++;
		}
		else {
			break;
		}
	}
	
	cout << ret << '\n';

	return 0;
}