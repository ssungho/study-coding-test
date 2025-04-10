#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main(void)
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, d, c;
        cin >> n >> d >> c;

        vector<vector<pair<int, int>>> graph(n + 1);
        vector<int> times(n + 1, INT_MAX);

        for (int i = 0; i < d; i++)
        {
            int a, b, s;
            cin >> a >> b >> s;
            graph[b].push_back({a, s});
        }

        times[c] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, c});

        while (!pq.empty())
        {
            int time = pq.top().first;
            int computer = pq.top().second;
            pq.pop();
            
            if (time > times[computer])
                continue;
            
            for (auto next : graph[computer])
            {
                if (times[next.first] > time + next.second)
                {
                    times[next.first] = time + next.second;
                    pq.push({times[next.first], next.first});
                }
            }
        }

        int total_hacked = 0;
        int last_time = 0;

        for (int i = 1; i <= n; i++)
        {
            if (times[i] != INT_MAX)
            {
                total_hacked++;
                last_time = max(last_time, times[i]);
            }
        }

        cout << total_hacked << " " << last_time << '\n';
    }

    return 0;
}