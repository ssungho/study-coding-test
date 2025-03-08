#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int dy[4]{1, -1, 0, 0};
int dx[4]{0, 0, -1, 1};

int main(void)
{

    int M, N;
    cin >> M >> N;

    vector<vector<int>> graph(N + 1, vector<int>(M + 1));

    for (int i = 1; i <= N; i++)
    {
        string temp;
        cin >> temp;

        for (int j = 0; j < (int)temp.size(); j++)
        {
            graph[i][j + 1] = temp[j] - '0';
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    vector<vector<int>> counts(N + 1, vector<int>(M + 1, INT_MAX));

    counts[1][1] = 0;

    pq.push({0, {1, 1}});

    while (!pq.empty())
    {
        pair<int, pair<int, int>> top = pq.top();

        int cost = top.first;
        int y = top.second.first;
        int x = top.second.second;

        pq.pop();

        if (cost > counts[y][x])
            continue;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny > 0 && ny <= N && nx > 0 && nx <= M)
            {
                if (counts[ny][nx] > cost + graph[ny][nx])
                {
                    counts[ny][nx] = cost + graph[ny][nx];
                    pq.push({counts[ny][nx], {ny, nx}});
                }
            }
        }
    }

    cout << counts[N][M];

    return 0;
}