#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> map(N + 1);

    for (int i = 0; i < M; i++)
    {
        int ai, bi, ci;
        cin >> ai >> bi >> ci;
        map[ai].push_back({bi, ci});
        map[bi].push_back({ai, ci});
    }

    vector<int> costs(N + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 1});

    while (!pq.empty())
    {
        pair<int, int> current = pq.top();
        int current_cost = current.first;
        int current_node = current.second;
        pq.pop();

        if (costs[current_node] < current_cost)
        {
            continue;
        }

        vector<pair<int, int>>& neighbor = map[current_node];
        for (auto& [next_node, next_cost] : neighbor)
        {
            if (costs[next_node] > next_cost + current_cost)
            {
                costs[next_node] = next_cost + current_cost;
                pq.push({costs[next_node], next_node});
            }
        }
    }

    cout << costs[N];

    return 0;
}