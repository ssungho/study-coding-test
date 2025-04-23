#include <iostream>
#include <queue>

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
    priority_queue<COST_EDGE, vector<COST_EDGE>, greater<COST_EDGE>> pq;

    for (int i = 0; i < E; i++)
    {
        COST_EDGE temp{};
        cin >> temp.second.first >> temp.second.second >> temp.first;
        pq.push(temp);
    }

    for (int i = 1; i <= V; i++)
    {
        parent[i] = i;
    }

    int total = 0;

    while (!pq.empty())
    {
        COST_EDGE top = pq.top();
        pq.pop();

        int cost = top.first;
        int node1 = top.second.first;
        int node2 = top.second.second;

        if (Union(node1, node2))
        {
            total += cost;
        }
    }

    cout << total;

    return 0;
}