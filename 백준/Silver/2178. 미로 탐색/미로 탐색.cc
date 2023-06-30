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

    while (!q.empty())
    {
        pair<int, int> cur_node = q.front();
        int y = cur_node.first;
        int x = cur_node.second;
        q.pop();

        // 상
        if (y - 1 >= 0 && !visited[y - 1][x] && maze[y - 1][x] == 1)
        {
            dis[y - 1][x] = dis[y][x] + 1;
            visited[y - 1][x] = true;
            q.push(make_pair(y - 1, x));
        }
        // 하
        if (y + 1 < 101 && !visited[y + 1][x] && maze[y + 1][x] == 1)
        {
            dis[y + 1][x] = dis[y][x] + 1;
            visited[y + 1][x] = true;
            q.push(make_pair(y + 1, x));
        }
        // 좌
        if (x - 1 >= 0 && !visited[y][x - 1] && maze[y][x - 1] == 1)
        {
            dis[y][x - 1] = dis[y][x] + 1;
            visited[y][x - 1] = true;
            q.push(make_pair(y, x - 1));
        }
        // 우
        if (x + 1 < 101 && !visited[y][x + 1] && maze[y][x + 1] == 1)
        {
            dis[y][x + 1] = dis[y][x] + 1;
            visited[y][x + 1] = true;
            q.push(make_pair(y, x + 1));
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