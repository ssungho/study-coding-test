#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

bool field[51][51]{ false };
bool visited[51][51]{ false };

int dx[4]{0, 0, -1, 1};
int dy[4]{-1, 1, 0, 0};

void BFS(int x, int y)
{
	visited[x][y] = true;
	queue<pair<int,int>> q;
	q.push({x, y});
	
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (nx > -1 && ny > -1 && nx < 51 && ny < 51)
			{
				if (!visited[nx][ny] && field[nx][ny])
				{
					visited[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
		}	
	}
}
void Reset()
{
	for(int i = 0; i < 51; i++)
		for (int j = 0; j < 51; j++)
		{
			field[i][j] = false;
			visited[i][j] = false;
		}
}

int main(void)
{
	int T, M, N, K;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> K;
		int x, y;
		// 배추 입력
		for (int j = 0; j < K; j++)
		{
			cin >> x >> y;
			field[y][x] = true;
		}
		// 지렁이 수
		int cnt = 0;
		for (int j = 0; j < M; j++)
			for (int k = 0; k < N; k++)
				// 방문한적 없고, 배추가 있는 땅이면 BFS를 실행.
				if (visited[k][j] == false && field[k][j] == true)
				{
					BFS(k, j);
					cnt++;
				}
		// 전역변수 초기화
		Reset();
		cout << cnt << '\n';
	}

	return 0;
}