#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

vector<vector<int>> graph(1001);
int dis[1001];
bool visited[1001];

int BFS(int start, int end, int x_node)
{
    if (start == x_node || end == x_node)
        return -1;

    queue<int> q;
    q.push(start);
    visited[start] = true;
    dis[start] = 1;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int i = 0; i < graph[current].size(); i++)
        {
            if (!visited[graph[current][i]] && graph[current][i] != x_node)
            {
                q.push(graph[current][i]);
                visited[graph[current][i]] = true;
                dis[graph[current][i]] = dis[current] + 1;
            }
        }
    }
    return dis[end];
}

int main(void)
{
    // 도시 수, 도로 수, 출발 도시, 도착 도시
    int N, M, S, E;

    // 도로 입력
    cin >> N >> M >> S >> E;
    for (int i = 0; i < M; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    // i번 도시가 공사중일 경우 이동경로
    for (int i = 1; i < N + 1; i++)
    {
        memset(dis, -1, sizeof(dis));
        memset(visited, false, sizeof(visited));

        int result = BFS(S, E, i);
        cout << result << '\n';
    }

    return 0;
}