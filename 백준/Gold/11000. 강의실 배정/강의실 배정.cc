#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

using ll = long long;
using pair_ll = pair<ll, ll>;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<pair_ll> times(N);
    priority_queue<ll, vector<ll>, greater<ll>> end_times;

    for (int i = 0; i < N; i++)
    {
        cin >> times[i].first >> times[i].second;
        end_times.push(times[i].second);
    }

    sort(times.begin(), times.end());

    int max_count = 0;
    for (int i = 0; i < N; i++)
    {
        int start_time = times[i].first;
        int end_time = end_times.top();

        if (end_time <= start_time)
        {
            end_times.pop();
            max_count--;
        }
        
        max_count++;
    }

    cout << max_count;

    return 0;
}