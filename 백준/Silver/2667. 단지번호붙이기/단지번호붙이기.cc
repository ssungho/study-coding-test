#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

vector<int> map[25]{};
bool visited[25][25];
vector<int> answer;

void BFS(int x, int y, int N)
{
    int cnt = 1;
    visited[x][y] = true;
    queue<pair<int, int>> q;
    q.push({ x, y });

    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { -1, 1, 0, 0 };

    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + cur_x;
            int ny = dy[i] + cur_y;
            if (nx > -1 && ny > -1 && nx < N && ny < N && map[nx][ny] == 1)
            {
                if (visited[nx][ny] == false)
                {
                    q.push({ nx, ny });
                    visited[nx][ny] = true;
                    cnt++;
                }
            }
        }
    }
    answer.push_back(cnt);
}

int main(void)
{
    int N;
    cin >> N;
    string temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;

        for (int j = 0; j < N; j++)
            map[i].push_back(temp[j] - '0');
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (visited[i][j] == false && map[i][j] == 1)
                BFS(i, j, N);
    }
    sort(answer.begin(), answer.end());

    cout << answer.size() << '\n';
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << '\n';

    return 0;
}