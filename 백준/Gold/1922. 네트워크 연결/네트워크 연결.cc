#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> network(N + 1);
    vector<bool> visited(N + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int start_node;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        network[a].push_back({b, c});
        network[b].push_back({a, c});
        start_node = a;
    }

    pq.push({0, start_node});

    int total = 0;

    while (!pq.empty())
    {
        int current_cost = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if (visited[current_node])
            continue;

        total += current_cost;
        visited[current_node] = true;

        vector<pair<int, int>> &linked = network[current_node];

        for (auto &next : linked)
        {
            int next_node = next.first;
            int next_cost = next.second;

            if (!visited[next_node])
            {
                pq.push({next_cost, next_node});
            }
        }
    }

    cout << total;

    return 0;
}