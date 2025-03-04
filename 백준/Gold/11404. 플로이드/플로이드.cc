#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> cities(n + 1, vector<int>(n + 1, -1));
    vector<vector<long long>> costs(n + 1, vector<long long>(n + 1));

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (cities[a][b] != -1)
            cities[a][b] = min(cities[a][b], c);
        else
            cities[a][b] = c;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                costs[i][j] = 0;
            else if (cities[i][j] != -1)
                costs[i][j] = cities[i][j];
            else
                costs[i][j] = INT_MAX;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                costs[j][k] = min(costs[j][k], costs[j][i] + costs[i][k]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (costs[i][j] >= INT_MAX)
                cout << 0 << " ";
            else
                cout << costs[i][j] << " ";
        }

        cout << '\n';
    }

    return 0;
}