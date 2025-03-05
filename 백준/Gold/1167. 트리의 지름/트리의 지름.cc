#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

long long max_distance{};
int far_node{};
bool visited[100001]{};
vector<vector<pair<int, int>>> graph(100001);

void DFS(int node, long long distance)
{
    if (distance > max_distance)
    {
        far_node = node;
        max_distance = distance;
    }

    visited[node] = true;

    vector<pair<int, int>> &current = graph[node];

    int size = current.size();
    for (int i = 0; i < size; i++)
    {
        int next_node = current[i].first;
        int next_distance = current[i].second;

        if (!visited[next_node])
        {
            DFS(next_node, next_distance + distance);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int V;
    cin >> V;

    int node1;
    for (int i = 0; i < V; i++)
    { 
        cin >> node1;

        while (true)
        {
            int node2, edge;

            cin >> node2;

            if (node2 == -1)
                break;

            cin >> edge;

            graph[node1].push_back({node2, edge});
            graph[node2].push_back({node1, edge});
        }
    }

    DFS(node1, 0);

    memset(visited, 0, sizeof(visited));

    DFS(far_node, 0);

    cout << max_distance;

    return 0;
}
