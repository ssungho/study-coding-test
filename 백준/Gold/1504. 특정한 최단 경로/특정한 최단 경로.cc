#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int Dijkstra(vector<vector<pair<int, int>>>& graph, int start, int dest, bool& fail)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<vector<int>> distances(graph.size(), vector<int>(graph.size(), INT_MAX));

    pq.push({0, start});
    distances[start][start] = 0;

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist > distances[start][node])
            continue;

        for (auto next : graph[node]) 
        {
            int next_node = next.first;
            int next_dist = next.second;

            if (distances[start][next_node] > dist + next_dist) 
            {
                distances[start][next_node] = dist + next_dist;
                pq.push({distances[start][next_node], next_node});
            }
        }
    }

    if (distances[start][dest] == INT_MAX)
        fail = true;
    return distances[start][dest];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, E;
    cin >> N >> E;

    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < E; i++)
    {
        int node1, node2, g;
        cin >> node1 >> node2 >> g;
        graph[node1].push_back({node2, g});
        graph[node2].push_back({node1, g});
    }

    int dest1, dest2;
    cin >> dest1 >> dest2;

    bool fail1 = false, fail2 = false;
    int path1 = Dijkstra(graph, 1, dest1, fail1) + Dijkstra(graph, dest1, dest2, fail1) + Dijkstra(graph, dest2, N, fail1);
    int path2 = Dijkstra(graph, 1, dest2, fail2) + Dijkstra(graph, dest2, dest1, fail2) + Dijkstra(graph, dest1, N, fail2);

    if (fail1)
        path1 = INT_MAX;
    if (fail2)
        path2 = INT_MAX;

    if (fail1 && fail2)
        cout << -1;
    else
        cout << min(path1, path2);

    return 0;
}