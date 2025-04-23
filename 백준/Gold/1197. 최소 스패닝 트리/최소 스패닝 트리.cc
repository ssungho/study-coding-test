#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> graph(V + 1);
    vector<bool> visited(V + 1, false);

    for (int i = 0; i < E; i++)
    {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        graph[v1].push_back({v2, cost});
        graph[v2].push_back({v1, cost});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int start_node = 0;
    while (graph[start_node].size() == 0)
    {
        start_node++;
    }

    int total = 0;
    pq.push({0, start_node});

    while (!pq.empty())
    {
        int current_cost = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if (visited[current_node])
            continue;

        visited[current_node] = true;
        total += current_cost;

        for (auto &node : graph[current_node])
        {
            int next_cost = node.second;
            int next_node = node.first;
            if (!visited[next_node])
            {
                pq.push({next_cost, next_node});
            }
        }
    }

    cout << total;

    return 0;
}