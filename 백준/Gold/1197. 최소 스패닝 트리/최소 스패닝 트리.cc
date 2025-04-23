#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using COST_EDGE = pair<int, pair<int, int>>;

int parent[10001]{};

int Find(int node)
{
    if (parent[node] == node)
    {
        return node;
    }

    return parent[node] = Find(parent[node]);
}

bool Union(int node1, int node2)
{
    int root1 = Find(node1);
    int root2 = Find(node2);

    if (root1 == root2)
    {
        return false;
    }

    parent[root2] = root1;

    return true;
}

int main(void)
{
    int V, E;
    cin >> V >> E;
    vector<COST_EDGE> edges(E);

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= V; i++)
    {
        parent[i] = i;
    }

    int total = 0;

    for (auto &edge_cost : edges)
    {
        int cost = edge_cost.first;
        int node1 = edge_cost.second.first;
        int node2 = edge_cost.second.second;

        if (Union(node1, node2))
        {
            total += cost;
        }
    }

    cout << total;

    return 0;
}