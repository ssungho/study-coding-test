#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool BFS(vector<vector<int>> &graph, vector<int> &group, vector<bool> &visited, int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    group[start] = 1;

    while (!q.empty())
    {
        int current_node = q.front();
        int current_group = group[current_node];
        q.pop();

        auto &neighbor = graph[current_node];
        int size = (int)neighbor.size();

        for (int i = 0; i < size; i++)
        {
            int next_node = neighbor[i];
            if (!visited[next_node])
            {
                group[next_node] = (current_group + 1) % 2;
                visited[next_node] = true;
                q.push(next_node);
            }
            else if (group[next_node] == group[current_node])
            {
                return false;
            }
        }
    }

    return true;
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> graph(V + 1);
        vector<int> group(V + 1, -1);
        vector<bool> visited(V + 1, false);

        for (int i = 0; i < E; i++)
        {
            int node1, node2;
            cin >> node1 >> node2;
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }

        bool result = true;
        for (int i = 1; i <= V; i++)
        {
            if (result && !visited[i])
                result = BFS(graph, group, visited, i);
                
            if (!result)
                break;
        }

        if (result)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}