#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, max_length;
bool visited[10001]{};
int costs[10001]{};
vector<vector<pair<int, int>>> graph(10001);

void DFS(int node, int cost)
{
    if (graph[node].size() == 0)
        return;

    visited[node] = true;

    vector<pair<int, int>> &current = graph[node];
    for (size_t i = 0; i < current.size(); i++)
    {
        if (!visited[current[i].first])
        {
            costs[current[i].first] += current[i].second + cost;
            DFS(current[i].first, costs[current[i].first]);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int node1, node2, value;
        cin >> node1 >> node2 >> value;

        graph[node1].push_back({node2, value});
        graph[node2].push_back({node1, value});
    }

    int max_length = 0;

    for (int i = 1; i <= n; i++)
    {
        DFS(i, 0);
        int length = *max_element(costs, costs + 10001);
        max_length = max(max_length, length);

        memset(visited, 0, sizeof(visited));
        memset(costs, 0, sizeof(costs));
    }

    cout << max_length;

    return 0;
}