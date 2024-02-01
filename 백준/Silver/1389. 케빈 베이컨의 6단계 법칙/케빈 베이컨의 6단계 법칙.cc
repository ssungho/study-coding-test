#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
bool visited[101];
int dist[101];

void reset(bool visited[], int dist[], int size)
{
    for (int i = 0; i < size; i++)
    {
        visited[i] = false;
        dist[i] = 999999;
    }
}

int search(vector<vector<int>> &graph, int start_node)
{
    visited[start_node] = true;
    queue<int> q;
    q.push(start_node);
    int result = 0;
    dist[start_node] = 0;

    while (!q.empty())
    {
        int cur_node = q.front();
        q.pop();
        for (int i = 0; i < graph[cur_node].size(); i++)
        {
            if (!visited[graph[cur_node][i]])
            {
                q.push(graph[cur_node][i]);
                visited[graph[cur_node][i]] = true;
                dist[graph[cur_node][i]] = min(dist[cur_node] + 1 , dist[graph[cur_node][i]]);
                result += dist[graph[cur_node][i]];
            }
        }
    }
    return result;
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    reset(visited, dist, n + 1);

    int node1, node2;
    for (int i = 0; i < m; i++)
    {
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    vector<pair<int, int>> result;
    for (int i = 1; i < n + 1; i++)
    {
        int cnt = search(graph, i);
        result.push_back(make_pair(cnt, i));
        reset(visited, dist, n + 1);
    }

    sort(result.begin(), result.end());

    cout << result.front().second;

    return 0;
}