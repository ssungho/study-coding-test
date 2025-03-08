#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < M; i++)
    {
        int start, dest, cost;
        cin >> start >> dest >> cost;
        graph[start].push_back({dest, cost});
    }

    int start, dest;
    cin >> start >> dest;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> costs(N + 1, INT_MAX);

    costs[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        pair<int, int> top = pq.top();
        
        int cost = top.first;
        int village = top.second;

        pq.pop();

        vector<pair<int, int>> &villages = graph[village];

        if (cost > costs[village]) 
            continue;

        for (auto &next : villages)
        {
            int next_village = next.first;
            int next_cost = next.second;

            if (costs[next_village] > next_cost + cost)
            {
                costs[next_village] = next_cost + cost;
                pq.push({costs[next_village], next_village});
            }
        }
    }

    cout << costs[dest];

    return 0;
}