#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>

using namespace std;

int dy[4]{1, -1, 0, 0};
int dx[4]{0, 0, -1, 1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++)
        {
            maze[i][j] = row[j] - '0';
            maze[i][j] = -(maze[i][j] - 1);
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    vector<vector<int>> costs(n, vector<int>(n, INT_MAX));

    costs[0][0] = maze[0][0];

    pq.push({costs[0][0], {0, 0}});

    while (!pq.empty())
    {
        pair<int, pair<int, int>> top = pq.top();
        int cost = top.first;
        int y = top.second.first;
        int x = top.second.second;
        pq.pop();

        if (costs[y][x] < cost)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if (ny >= 0 && ny < n && nx >= 0 && nx < n)
            {
                if (costs[ny][nx] > cost + maze[ny][nx])
                {
                    costs[ny][nx] = cost + maze[ny][nx];
                    pq.push({costs[ny][nx], {ny, nx}});
                }
            }
        }
    }

    cout << costs[n - 1][n - 1];

    return 0;
}