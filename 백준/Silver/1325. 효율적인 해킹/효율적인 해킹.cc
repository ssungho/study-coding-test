#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

bool visited[10001]{};
vector<int> answer;
int max_count = 0;

int dfs(vector<vector<int>>& graph, int computer) {
    int count = 1;
    visited[computer] = true;
    auto& trust = graph[computer];
    for (auto next : trust) {
        if (!visited[next]) count += dfs(graph, next);
    }
    return count;
}

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    
    for (int i = 0 ; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        int count = dfs(graph, i);

        if (count > max_count) {
            max_count = count;
            answer.clear();
            answer.push_back(i);
        }

        else if (count == max_count) {
            answer.push_back(i);
        }
    }

    for (auto com : answer) {
        cout << com << " ";
    }

    return 0;
}