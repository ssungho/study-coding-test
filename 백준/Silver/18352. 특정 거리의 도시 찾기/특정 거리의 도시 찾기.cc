#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main(void) {

    int N, M, K, X;
    cin >> N >> M >> K >> X;

    vector<vector<int>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }

    vector<int> costs(N + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    costs[X] = 0;

    pq.push({0, X});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        vector<int>& linked = graph[current];
        int size = (int)linked.size();
        for (int i = 0; i < size; i++) {
            if (costs[linked[i]] > cost + 1) {
                costs[linked[i]] = cost + 1;
                pq.push({cost + 1, linked[i]});
            }
        }
    }

    vector<int> cities;
    for (int i = 1; i <= N; i++) {
        if (costs[i] == K)
            cities.push_back(i);
    }

    if (cities.size() == 0) {
        cout << -1;
    }
    else {
        for (auto city : cities) {
            cout << city << '\n';
        }
    }

    return 0;
}