#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int V, E;
    cin >> V >> E;

    vector<vector<int>> dist(V + 1, vector<int>(V + 1, INT_MAX));

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c); 
    }

    for (int i = 1; i <= V; i++) 
    {
        dist[i][i] = 0;
    }

    for (int k = 1; k <= V; k++)
    {
        for (int i = 1; i <= V; i++)
        {
            for (int j = 1; j <= V; j++)
            {
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                {
                    continue;
                }
                else
                {
                    dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
                }
            }
        }
    }

    int min_cycle = INT_MAX;
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if (i == j)
            {
                continue;
            }

            if (dist[i][j] != INT_MAX && dist[j][i] != INT_MAX)
            {
                min_cycle = min(min_cycle, dist[i][j] + dist[j][i]);
            }
        }
    }

    min_cycle = min_cycle == INT_MAX ? -1 : min_cycle;

    cout << min_cycle;

    return 0;
}