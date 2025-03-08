#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int Dijkstra(vector<vector<pair<int, int>>> &graph, int D)
{
    vector<int> distances(D + 1, INT_MAX);
    distances[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});

    while (!pq.empty())
    {
        pair<int, int> dist_load = pq.top();
        int dist = dist_load.first;
        int load = dist_load.second;
        pq.pop();

        vector<pair<int, int>> &current_loads = graph[load];
        int size = current_loads.size();
        for (int i = 0; i < size; i++)
        {
            int next_load = current_loads[i].first;
            int next_dist = current_loads[i].second;

            if (distances[next_load] > next_dist + dist)
            {
                distances[next_load] = next_dist + dist;
                pq.push({distances[next_load], next_load});
            }
        }
    }

    return distances[D];
}

int main(void)
{
    int N, D;
    cin >> N >> D;

    vector<vector<pair<int, int>>> graph(D + 1);

    for (int i = 0; i < N; i++)
    {
        int start, end, length;
        cin >> start >> end >> length;

        if (end > D)
            continue;

        graph[start].push_back({end, length});
    }

    for (int i = 0; i < D; i++)
    {
        graph[i].push_back({i + 1, 1});
    }

    cout << Dijkstra(graph, D);

    return 0;
}