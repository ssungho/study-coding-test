#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> graph(N + 1);
    vector<bool> visited(N + 1, false);

    for (int i = 0; i < N - 1; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    vector<int> answer(N + 1);
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        vector<int> &temp = graph[current];

        for (int i = 0; i < temp.size(); i++)
        {
            if (!visited[temp[i]])
            {
                answer[temp[i]] = current;
                q.push(temp[i]);
                visited[temp[i]] = true;
            }
        }
    }

    for (int i = 2; i <= N; i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}