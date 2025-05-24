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
    }

    sort(times.begin(), times.end());
    end_times.push(times[0].second);

    for (int i = 1; i < N; i++)
    {
        if (end_times.top() <= times[i].first)
        {
            end_times.pop();
        }

        end_times.push(times[i].second);
    }

    cout << end_times.size();

    return 0;
}