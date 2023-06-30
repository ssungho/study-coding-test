#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int maze[101][101]{ 0 };
int dis[101][101]{ 1 };
bool visited[101][101]{};

void Search(pair<int, int> node)
{
    visited[node.first][node.second] = true;
    queue<pair<int, int>> q;
    q.push(node);

    // 상 하 좌 우
    const int dy[4]{-1, 1, 0, 0};
    const int dx[4]{0, 0, -1, 1};

    while (!q.empty())
    {
        pair<int, int> cur_node = q.front();
        int y = cur_node.first;
        int x = cur_node.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny >= 0 && nx >= 0 && ny < 101 && nx < 101)
            {
                if (!visited[ny][nx] && maze[ny][nx] == 1)
                {
                    dis[ny][nx] = dis[y][x] + 1;
                    visited[ny][nx] = true;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
}

int main(void)
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
            if (temp[j] == '1')
                maze[i][j] = 1;
    }

    pair<int, int> start = make_pair(0, 0);
    Search(start);
    cout << dis[N - 1][M - 1];
    return 0;
}