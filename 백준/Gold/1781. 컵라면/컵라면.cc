#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> homeworks(N);
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++)
    {
        cin >> homeworks[i].first >> homeworks[i].second;
    }

    sort(homeworks.begin(), homeworks.end());

    int total = 0;
    for (int i = 0; i < N; i++)
    {
        pq.push(homeworks[i].second);
        total += homeworks[i].second;
        if (homeworks[i].first < pq.size())
        {
            total -= pq.top();
            pq.pop();
        }
    }

    cout << total << '\n';

    return 0;
}