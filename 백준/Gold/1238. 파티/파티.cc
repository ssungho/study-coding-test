#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int N, M, X;
vector<vector<pair<int, int>>> villages;

vector<int> Dijkstra(int start)
{
    vector<int> times(N + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    times[start] = 0;

    while (!pq.empty())
    {
        int current_time = pq.top().first;
        int current_village = pq.top().second;
        pq.pop();

        if (current_time > times[current_village])
            continue;

        for (auto &next : villages[current_village])
        {
            int next_village = next.first;
            int next_time = next.second;

            if (times[next_village] > current_time + next_time)
            {
                times[next_village] = current_time + next_time;
                pq.push({times[next_village], next_village});
            }
        }
    }

    return times;
}

int main()
{
    cin >> N >> M >> X;
    villages.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int village1, village2, time;
        cin >> village1 >> village2 >> time;
        villages[village1].push_back({village2, time});
    }

    vector<int> from = Dijkstra(X);

    int max_time = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i != X)
        {
            vector<int> to = Dijkstra(i);
            max_time = max(max_time, from[i] + to[X]);
        }
    }

    cout << max_time << endl;
    return 0;
}