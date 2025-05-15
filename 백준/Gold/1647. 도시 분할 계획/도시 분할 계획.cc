#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using COST_NODE = pair<int, pair<int, int>>;

int Find(vector<int> &parent, int node)
{
    if (parent[node] == node)
        return node;
    return parent[node] = Find(parent, parent[node]);
}

bool Union(vector<int> &parent, int node1, int node2)
{
    int root1 = Find(parent, node1);
    int root2 = Find(parent, node2);

    if (root1 == root2)
    {
        return false;
    }

    if (root1 < root2)
    {
        parent[root2] = root1;
    }
    else
    {
        parent[root1] = root2;
    }

    return true;
}

int main(void)
{
    int N, M;
    cin >> N >> M;

    vector<int> parent(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    priority_queue<COST_NODE, vector<COST_NODE>, greater<COST_NODE>> pq;

    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        pq.push({C, {A, B}});
    }

    int total = 0;
    int last = 0;

    while (!pq.empty())
    {
        COST_NODE top = pq.top();
        int cost = top.first;
        int node1 = top.second.first;
        int node2 = top.second.second;
        pq.pop();

        if (Union(parent, node1, node2))
        {
            total += cost;
            last = cost;
        }
    }

    cout << total - last;

    return 0;
}