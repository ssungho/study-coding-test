#include <iostream>
#include <queue>
using namespace std;

int house[1001][1001];
int types[31];
bool visited[1001][1001];

void BFS(int y, int x, int m, int k)
{
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};

    int type = m;

    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;

    int count = 1;
    while (!q.empty())
    {
        int curr_y = q.front().first;
        int curr_x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = curr_y + dy[i];
            int nx = curr_x + dx[i];

            bool in_range = ny > 0 && nx > 0 && ny < 1001 && nx < 1001;
            if (in_range && !visited[ny][nx])
            {
                if (house[ny][nx] == type)
                {
                    q.push({ny, nx});
                    visited[ny][nx] = true;
                    count++;
                }
            }
        }
    }
    if (count >= k)
        types[type]++;
}

int main(void)
{
    int N, K;
    cin >> N >> K;
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            int M;
            cin >> M;
            house[i][j] = M;
        }
    }

    for (int i = 1; i < N + 1; i++)
        for (int j = 1; j < N + 1; j++)
            BFS(i, j, house[i][j], K);

    int max_count = -1;
    int answer;
    for (int i = 1; i < 31; i++)
    {
        if (types[i] >= max_count)
        {
            max_count = types[i];
            answer = i;
        }
    }
    cout << answer;

    return 0;
}