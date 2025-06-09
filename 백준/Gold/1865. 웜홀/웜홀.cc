#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX_T{10001};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC;
    cin >> TC;

    while (TC--)
    {
        int N, M, W;
        cin >> N >> M >> W;

        vector<vector<pair<int, int>>> spot(N + 1);
        vector<int> costs(N + 1, 0);

        for (int i = 0; i < M; i++)
        {
            int S, E, T;
            cin >> S >> E >> T;
            spot[S].push_back({E, T});
            spot[E].push_back({S, T});
        }

        for (int i = 0; i < W; i++)
        {
            int S, E, T;
            cin >> S >> E >> T;
            spot[S].push_back({E, -T});
        }

        for (int i = 1; i < N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                vector<pair<int, int>> &ref = spot[j];
                for (auto &p : ref)
                {
                    costs[j] = min(costs[j], costs[p.first] + p.second);
                }
            }
        }

        bool is_find = false;

        for (int i = 1; i <= N; i++)
        {
            vector<pair<int, int>> &ref = spot[i];
            for (auto &p : ref)
            {
                if (costs[i] > costs[p.first] + p.second)
                {
                    is_find = true;
                    break;
                }
            }

            if (is_find)
                break;
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