#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

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
        return false;

    if (root1 < root2)
        parent[root1] = root2;
    else
        parent[root2] = root1;

    return true;
}

int main(void)
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> graph(N + 1);

        int start;
        for (int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
            start = a;
        }

        vector<int> parent(N + 1, 0);
        for (int i = 1; i <= N; i++)
        {
            parent[i] = i;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({1, start});
        int result = 0;
        while (!pq.empty())
        {
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto next : graph[node])
            {
                if (Union(parent, node, next))
                {
                    result++;
                    pq.push({cost + 1, next});
                }
            }
        }

        cout << result << '\n';
    }

    return 0;
}