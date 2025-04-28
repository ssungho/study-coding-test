#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int N, K;
        cin >> N >> K;

        vector<int> build_time(N + 1);
        vector<vector<int>> build(N + 1);
        vector<int> degree(N + 1, 0);

        for (int i = 1; i <= N; i++)
        {
            cin >> build_time[i];
        }

        for (int i = 0; i < K; i++)
        {
            int node1, node2;
            cin >> node1 >> node2;
            build[node1].push_back(node2);
            degree[node2]++;
        }

        vector<int> dp(N + 1, 0);
        queue<int> q;

        for (int i = 1; i <= N; i++)
        {
            if (degree[i] == 0)
            {
                q.push(i);
                dp[i] = build_time[i];
            }
        }

        int dest = 0;
        cin >> dest;

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            for (auto next : build[current])
            {
                dp[next] = max(dp[next], dp[current] + build_time[next]);
                if (--degree[next] == 0)
                {
                    q.push(next);
                }
            }
        }

        cout << dp[dest] << '\n';
    }

    return 0;
}