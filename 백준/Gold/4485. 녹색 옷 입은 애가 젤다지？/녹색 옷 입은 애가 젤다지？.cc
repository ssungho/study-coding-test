#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int dy[4]{1, -1, 0, 0};
int dx[4]{0, 0, -1, 1};

using Lost_YX = pair<int, pair<int, int>>;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test = 0;
    while (true)
    {
        int N;
        cin >> N;

        if (N == 0)
            break;

        test++;

        vector<vector<int>> graph(N, vector<int>(N));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> graph[i][j];
            }
        }

        priority_queue<Lost_YX, vector<Lost_YX>, greater<Lost_YX>> pq;

        pq.push({graph[0][0], {0, 0}});

        vector<vector<int>> lost_rupees(N, vector<int>(N, INT_MAX));

        while (!pq.empty())
        {
            Lost_YX lost_yx = pq.top();
            int rupee = lost_yx.first;
            int y = lost_yx.second.first;
            int x = lost_yx.second.second;
            pq.pop();

            if (rupee > lost_rupees[y][x])
                continue;

            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny >= 0 && ny < N && nx >= 0 && nx < N)
                {
                    if (lost_rupees[ny][nx] > graph[ny][nx] + rupee)
                    {
                        lost_rupees[ny][nx] = graph[ny][nx] + rupee;
                        pq.push({lost_rupees[ny][nx], {ny, nx}});
                    }
                }
            }
        }

        cout << "Problem " << test << ": " << lost_rupees[N - 1][N - 1] << '\n';
    }

    return 0;
}