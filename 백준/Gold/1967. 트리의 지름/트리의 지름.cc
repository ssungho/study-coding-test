#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, max_length, far_node;
bool visited[10001]{};
vector<vector<pair<int, int>>> graph(10001);

void DFS(int node, int distance)
{
    if (max_length < distance)
    {
        far_node = node;
        max_length = distance;
    }

    visited[node] = true;

    vector<pair<int, int>> &current = graph[node];
    for (size_t i = 0; i < current.size(); i++)
    {
        if (!visited[current[i].first])
        {
            DFS(current[i].first, current[i].second + distance);
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

    int root_node = 1;

    DFS(root_node, 0);

    memset(visited, 0, sizeof(visited));

    DFS(far_node, 0);

    cout << max_length;

    return 0;
}