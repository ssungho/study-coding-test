#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> graph(100001);
bool visited[100001];
vector<pair<float, vector<int>>> container;
void BFS(int start)
{
    vector<int> nodes;
    queue<int> q;

    q.push(start);
    nodes.push_back(start);

    int edgeCount = 0;
    visited[start] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < graph[curr].size(); i++)
        {
            int next = graph[curr][i];
            if (!visited[next])
            {
                q.push(next);
                nodes.push_back(next);
                visited[next] = true;
            }
            edgeCount++;
        }
    }

    float f = (float)edgeCount / nodes.size();
    sort(nodes.begin(), nodes.end());
    // ? f를 음수로 넣은 이유는 f에 대해서 내림차순으로 저장하고 v에 대해서는 오름차순으로 정렬하기 위해서.
    container.push_back({-f, nodes});
}

int main(void)
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    for (int i = 0; i < N + 1; ++i)
    {
        if (!visited[i])
        {
            BFS(i);
        }
    }

    sort(container.begin(), container.end());

    for (int i = 0; i < container.front().second.size(); ++i)
    {
        cout << container.front().second[i] << " ";
    }

    return 0;
}