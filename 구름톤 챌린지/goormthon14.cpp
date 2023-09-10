#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> graph(2001);
bool visited[2001];

pair<int, int> BFS(int start_node)
{
    queue<int> q;
    q.push(start_node);
    visited[start_node] = true;

    int count = 1;
    int last_node = start_node;

    while(!q.empty())
    {
        int curr_node = q.front();
        q.pop();

        if(graph[curr_node].size() > 0)
        {
            for(int i = 0; i < graph[curr_node].size(); i++)
            {
                int next_node = graph[curr_node][i];
                if(visited[next_node] == false)
                {
                    visited[next_node] = true;
                    q.push(next_node);
                    count++;
                    last_node = next_node;
                    break;
                }
            }
        }
    }

    return {count, last_node};
}

int main()
{
    // 방문할 수 있으면서 가장 작은 노드로 이동
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    for(int i = 1; i < N + 1; i++)
        sort(graph[i].begin(), graph[i].end());
    
    pair<int,int> result = BFS(K);
    cout << result.first << " " << result.second;

    return 0;
}