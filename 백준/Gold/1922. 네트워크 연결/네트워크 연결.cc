#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Find(vector<int> &parent, int v)
{
    if (parent[v] != v)
        parent[v] = Find(parent, parent[v]);
    return parent[v];
}

bool Union(vector<int> &parent, int v1, int v2)
{
    int parent_v1 = Find(parent, v1);
    int parent_v2 = Find(parent, v2);

    if (parent_v1 == parent_v2)
        return false;

    if (parent_v1 > parent_v2)
        parent[parent_v2] = parent_v1;
    else
        parent[parent_v1] = parent_v2;

    return true;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;

    vector<pair<int, pair<int, int>>> network;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        network.push_back({c, {a, b}});
    }

    sort(network.begin(), network.end());

    vector<int> parent(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    int total = 0;

    for (auto &cost_nodes : network)
    {
        int cost = cost_nodes.first;
        int v1 = cost_nodes.second.first;
        int v2 = cost_nodes.second.second;
        
        if (Union(parent, v1, v2))
        {
            total += cost;
        }
    }

    cout << total;

    return 0;
}