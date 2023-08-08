#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> graph(V + 1);
    vector<int> memo(V + 1);
    vector<bool> visited(V + 1);

    int start_node;
    cin >> start_node;

    for (int i = 0; i < V + 1; i++)
    {
        memo[i] = INT32_MAX;
        visited[i] = false;
    }
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w}); // 수정된 부분
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start_node}); // 가중치 노드
    memo[start_node] = 0;

    while (!pq.empty())
    {
        int curr_node = pq.top().second;
    
        pq.pop();
        if (!visited[curr_node])
        {
            for (int i = 0; i < graph[curr_node].size(); i++)
            {
                memo[graph[curr_node][i].first] = min(memo[graph[curr_node][i].first], graph[curr_node][i].second + memo[curr_node]);
                pq.push({memo[graph[curr_node][i].first], graph[curr_node][i].first});
            }
        }
        visited[curr_node] = true;
    }

    for(int i = 1; i < V + 1; i++)
    {
        if(memo[i] == INT32_MAX)
            cout << "INF" << '\n';
        else
            cout << memo[i] << '\n';
    }

    return 0;
}