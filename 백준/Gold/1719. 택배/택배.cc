#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INT_MAX));
    vector<vector<int>> costs(n + 1, vector<int>(n + 1, INT_MAX));
    vector<vector<int>> result(n + 1, vector<int>(n + 1, INT_MAX));

    for (int i = 0; i < m; i++) {
        int node1, node2, time;
        cin >> node1 >> node2 >> time;

        if (graph[node1][node2] > time) {
            graph[node1][node2] = time;
            result[node1][node2] = node2;
        }
        if (graph[node2][node1] > time) {
            graph[node2][node1] = time;
            result[node2][node1] = node1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) costs[i][j] = 0;
            else costs[i][j] = graph[i][j];
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;

                if (costs[i][k] == INT_MAX || costs[k][j] == INT_MAX)
                    continue;

                int cost1 = costs[i][k] + costs[k][j];
                int cost2 = costs[i][j];
                
                if (cost1 < cost2) {
                    costs[i][j] = cost1;
                    result[i][j] = result[i][k];
                }
                else {
                    costs[i][j] = cost2;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) cout << "- ";
            else cout << result[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}