#include <iostream>
#include <string>
#include <queue>
#include <memory.h>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main(void)
{
    int N, M;
    cin >> N >> M;

    char campus[N][M];
    bool visited[N][M];
    pair<int, int> start_pos;

    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;

        for (int j = 0; j < temp.length(); j++)
        {
            if (temp[j] == 'I')
                start_pos = make_pair(i, j);

            campus[i][j] = temp[j];
        }

        memset(visited, false, sizeof(bool) * M);
    }

    int count = 0;

    queue<pair<int, int>> q;
    q.push(start_pos);
    visited[start_pos.first][start_pos.second] = true;

    while (!q.empty())
    {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];

            if (!visited[ny][nx] &&
                0 <= ny && ny < N &&
                0 <= nx && nx < M && 
                campus[ny][nx] != 'X')
            {
                q.push(make_pair(ny, nx));
                visited[ny][nx] = true;
                if(campus[ny][nx] == 'P')
                    count++;
            }
        }
    }

    if (count == 0)
        cout << "TT";
    else
        cout << count;

    return 0;
}