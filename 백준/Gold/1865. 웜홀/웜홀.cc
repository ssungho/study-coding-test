#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX_T{10001};

int main(void)
{
    int TC;
    cin >> TC;

    while (TC--)
    {
        int N, M, W;
        cin >> N >> M >> W;

        vector<vector<int>> spot(N + 1, vector<int>(N + 1, MAX_T));
        vector<vector<int>> wormhole(N + 1, vector<int>(N + 1, MAX_T));
        vector<vector<int>> costs(N + 1, vector<int>(N + 1, MAX_T));

        for (int i = 0; i < M; i++)
        {
            int S, E, T;
            cin >> S >> E >> T;
            spot[S][E] = min(spot[S][E], T);
            spot[E][S] = min(spot[E][S], T);
        }

        for (int i = 0; i < W; i++)
        {
            int S, E, T;
            cin >> S >> E >> T;
            wormhole[S][E] = T;
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i == j)
                {
                    costs[i][j] = 0;
                }
                else if (spot[i][j] != MAX_T)
                {
                    costs[i][j] = spot[i][j];
                }

                if (wormhole[i][j] != MAX_T)
                {
                    costs[i][j] = min(costs[i][j], -wormhole[i][j]);
                }
            }
        }

        for (int k = 1; k <= N; k++)
        {
            for (int i = 1; i <= N; i++)
            {
                for (int j = 1; j <= N; j++)
                {
                    costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
                }
            }
        }

        bool is_find = false;
        for (int i = 1; i <= N; i++)
        {
            if (costs[i][i] < 0)
            {
                is_find = true;
                break;
            }
        }

        if (is_find)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}