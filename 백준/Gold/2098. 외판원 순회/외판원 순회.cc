#include <iostream>
#include <climits>

using namespace std;

constexpr int MAX_N{16};
int graph[MAX_N][MAX_N]{};
int dp[1 << MAX_N][MAX_N]{};
int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    int mask_max = 1 << N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < mask_max; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = INT_MAX;
        }
    }

    dp[1][0] = 0;

    for (int mask = 1; mask < mask_max; ++mask)
    {
        for (int i = 0; i < N; ++i)
        {
            if (!(mask & (1 << i)) || dp[mask][i] == INT_MAX)
                continue;

            for (int j = 0; j < N; ++j)
            {
                if ((mask & (1 << j)) || graph[i][j] == 0)
                    continue;

                int next_mask = mask | (1 << j);
                int next_cost = dp[mask][i] + graph[i][j];

                dp[next_mask][j] = min(dp[next_mask][j], next_cost);
            }
        }
    }

    int result = INT_MAX;
    for (int i = 1; i < N; ++i)
    {
        if (graph[i][0] == 0)
            continue;
        
        if (dp[mask_max - 1][i] == INT_MAX)
            continue;

        result = min(result, dp[mask_max - 1][i] + graph[i][0]);
    }

    cout << result << '\n';
    
    return 0;
}