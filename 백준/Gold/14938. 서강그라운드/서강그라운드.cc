#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main(void)
{
    int n, m, r;
    cin >> n >> m >> r;

    vector<int> t(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }

    vector<vector<pair<int, int>>> map(n + 1);

    for (int i = 0; i < r; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        map[a].push_back({b, l});
        map[b].push_back({a, l});
    }

    int max_item = 0;

    for (int i = 1; i <= n; i++)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, i});

        vector<int> lengths(n + 1, INT_MAX);
        lengths[i] = 0;

        while (!pq.empty())
        {
            pair<int, int> top = pq.top();
            int length = top.first;
            int node = top.second;
            pq.pop();

            if (length > lengths[node])
                continue;

            vector<pair<int, int>> &neighbor = map[node];
            int size = neighbor.size();

            for (int j = 0; j < size; j++)
            {
                int next_node = neighbor[j].first;
                int next_length = neighbor[j].second + length;

                if (lengths[next_node] > next_length)
                {
                    lengths[next_node] = next_length;
                    pq.push({next_length, next_node});
                }
            }
        }

        int item = 0;
        for (int j = 1; j <= n; j++)
        {
            if (lengths[j] <= m)
            {
                item += t[j];
            }
        }

        max_item = max(item, max_item);
    }

    cout << max_item;

    return 0;
}