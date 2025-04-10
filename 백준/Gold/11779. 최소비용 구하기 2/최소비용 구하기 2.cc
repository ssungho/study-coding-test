#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);

    int start, dest, cost;
    for (int i = 0; i < m; i++)
    {
        cin >> start >> dest >> cost;
        graph[start].push_back({dest, cost});
    }

    cin >> start >> dest;

    vector<pair<int, pair<int, int>>> costs(n + 1, {INT_MAX, {0, 0}});

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});

    costs[start].first = 0;
    costs[start].second = { start, 1 };

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int city = pq.top().second;
        pq.pop();

        if (cost > costs[city].first)
            continue;

        for (auto &next : graph[city])
        {
            int next_city = next.first;
            int next_cost = next.second;

            if (costs[next_city].first > cost + next_cost)
            {
                costs[next_city].first = cost + next_cost;
                pq.push({costs[next_city].first, next_city});
                costs[next_city].second = { city, costs[city].second.second + 1 };
            }
        }
    }

    vector<int> path;
    int current = dest;

    while (true) 
    {
        path.push_back(current);
        if (current == start) break;
        current = costs[current].second.first;
    }

    reverse(path.begin(), path.end());

    cout << costs[dest].first << '\n'
         << costs[dest].second.second << '\n';

    for (auto city : path)
     {
        cout << city << " ";
    }

    return 0;
}